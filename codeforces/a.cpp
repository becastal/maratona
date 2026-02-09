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
	vector<string> A(n);
	vector<vector<int>> Ha(n, vector<int>(m));
	vector<vector<int>> B(m);
 
	for (auto& i : A) cin >> i;
	for (int j = 0; j < m; j++) {
		for (int l = 0, r; l < n; l = r) {
			r = l + 1;
			if (A[l][j] == '*') {
				Ha[l][j] = 0;
				continue;
			}
 
			while (r < n and A[r][j] == '.') r++;
			for (int i = l; i < r; i++) {
				Ha[i][j] = r;	
			}
		}
	}
 
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << Ha[i][j] << " \n"[j == m-1];
	//	}
	//}
 
	int res = 0;
	for (int i = 0; i < n; i++) {
		vector<int> H(m);
		for (int j = 0; j < m; j++) {
			H[j] = max(0, Ha[i][j] - i);
		}

		for (int i : H) cout << i << ' '; cout << endl;
 
		stack<int> S;
		vector<int> L(m), R(m);
		for (int j = 0; j < m; j++) {
			while (S.size() and H[S.top()] >= H[j]) {
				S.pop();	
			}
			L[j] = (S.size() ? S.top() : -1);
			S.push(j);
		}
 
		while (S.size()) S.pop();
		for (int j = m-1; j >= 0; j--) {
			while (S.size() and H[S.top()] >= H[j]) {
				S.pop();	
			}
			R[j] = (S.size() ? S.top() : m);
			S.push(j);
		}
 
		for (int j = 0; j < m; j++) {
			res = max(res, H[j] * (R[j] - L[j] - 1));
		}
 
		//for (int j = 0; j < m; j++) {
		//	printf("(%d, [%d, %d]) ", H[j], L[j], R[j]);
		//}
		//printf("\n");
	}
	cout << res << endl;
 
	return(0);
}
 
int main()
{
    _;
 
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
