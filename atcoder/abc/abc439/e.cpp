#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Bit {
	int n;
	vector<int> F;

	Bit(int n_) : n(n_), F(n + 1) {};

	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) {
			F[i] = max(F[i], x);
		}
	}

	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) {
			res = max(res, F[i]);
		}
		return res;
	}
};

int solve() {
	int n; cin >> n;

	vector<int> A(n), B(n), Comp(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
		Comp[i] = B[i];
	}

	sort(all(Comp));
	Comp.erase(unique(all(Comp)), Comp.end());
	for (int& i : B) {
		i = lower_bound(all(Comp), i) - Comp.begin();
	}
	int m = (int)Comp.size();

	vector<int> O(n);
	iota(all(O), 0);
	sort(all(O), [&](int a, int b) {
		if (A[a] != A[b]) return A[a] < A[b];
		return B[a] > B[b];
	});

	Bit bit(m);
	for (int i : O) {
		int b = B[i], mx = b ? bit.pref(b - 1) : 0;
		bit.update(b, mx + 1);
	}
	cout << bit.pref(m - 1) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

