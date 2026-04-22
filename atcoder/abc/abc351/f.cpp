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
	vector<int> a;

	Bit(int n_) : n(n_), a(n + 1) { }
	void update(int i, int x) {
		for (i++; i <= n; i += i&-i) {
			a[i] += x;
		}
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i -= i&-i) {
			res += a[i];
		}
		return res;
	}
};

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<int> Comp(A), Id(n);
	sort(all(Comp));
	Comp.erase(unique(all(Comp)), Comp.end());
	for (int i = 0; i < n; i++) {
		Id[i] = lower_bound(all(Comp), A[i]) - Comp.begin();
	}

	int m = (int)Comp.size(), res = 0;
	Bit bit_cont(m), bit_soma(m);
	for (int i = 0; i < n; i++) {
		bit_cont.update(Id[i], +1);
		bit_soma.update(Id[i], +A[i]);
		res += bit_cont.pref(Id[i]) * A[i] - bit_soma.pref(Id[i]);
	}
	cout << res << endl;

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

