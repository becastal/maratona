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
		for (i++; i <= n; i += i&-i) {
			A[i] = max(A[i], x);
		}
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i -= i&-i) {
			res = max(res, A[i]);
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

	vector<int> A_(A);
	sort(all(A_));
	Bit bit(n);

	int res = 0;
	vector<int> Dp(n);
	for (int i = 0; i < n; i++) {
		A[i] = lower_bound(all(A_), A[i]) - A_.begin();
		Dp[i] = bit.pref(A[i] - 1) + 1;
		bit.update(A[i], Dp[i]);
		res = max(res, Dp[i]);	
	}

	vector<int> Res(n), B(n + 1, LLONG_MIN);
	for (int i = n-1; i >= 0; i--) {
		if (Dp[i] == res or B[Dp[i]] > A[i]) {
			B[Dp[i] - 1] = max(B[Dp[i] - 1], A[i]);
			Res[i] = 1;
		}
	}

	cout << count(all(Res), 1) << endl;
	for (int i = 0; i < n; i++) if (Res[i]) {
		cout << (i + 1) << " ";
	}
	cout << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

