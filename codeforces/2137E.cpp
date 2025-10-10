#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	sort(all(A));

	int mex = 0, p = 0;
	for (; p < n; p++) {
		if (A[p] == mex) mex++;
		else break;
	}

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < 10; i++) {
		auto mex = [&A, n](int j) {
			vector<int> vis(n+1, 0);
			for (int i = 0; i < n; i++) if (i != j) {
				vis[A[i]] = 1;
			}
			int res = 0;
			while (vis[res]) res++;
			return res;
		};
		vector<int> B(n);
		for (int j = 0; j < n; j++) {
			B[j] = mex(j);
			cout << B[j] << " \n"[j==n-1];
		}
		A = move(B);
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

