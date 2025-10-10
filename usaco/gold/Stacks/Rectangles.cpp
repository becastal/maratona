#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> A(n, vector<int>(m)), Ha(A);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}

	for (int j = 0; j < m; j++) {
		for (int l = 0, r; l < n; l = r) {
			r = l + 1;
			while (r < n and A[l][j] == A[r][j]) r++;

			for (int i = l; i < r; i++) {
				Ha[i][j] = r - i;	
			}
		}
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		vector<int> H = Ha[i];

		for (int l = 0, r; l < m; l = r) {
			r = l + 1;
			while (r < m and A[i][l] == A[i][r]) r++;

			stack<int> S;
			vector<int> L(m), R(m);
			for (int j = l; j < r; j++) {
				while (S.size() and H[S.top()] >= H[j]) {
					S.pop();
				}
				L[j] = (S.size() ? S.top() : l-1);
				S.push(j);
			}
			
			while (S.size()) S.pop();
			for (int j = r-1; j >= 0; j--) {
				while (S.size() and H[S.top()] > H[j]) {
					S.pop();
				}
				R[j] = (S.size() ? S.top() : r);
				S.push(j);
			}

			for (int j = l; j < r; j++) {
				res += ll(H[j]) * (j - L[j]) * (R[j] - j);
			}
		}
	}
	cout << res << endl;

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
