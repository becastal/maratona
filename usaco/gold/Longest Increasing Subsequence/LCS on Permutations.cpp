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
	vector<int> A;

	Bit (int n_) : n(n_), A(n + 1) {}
	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) {
			A[i] = max(A[i], x);
		}
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) {
			res = max(res, A[i]);
		}
		return res;
	}
};

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n), B_(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> B[i];
		B_[B[i]] = i;
	}

	Bit bit(n + 1);	
	for (int a : A) {
		bit.update(B_[a], bit.pref(B_[a]) + 1);
	}
	cout << bit.pref(n) << endl;

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

