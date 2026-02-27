#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k, res = 0; cin >> n >> k;
	
	vector<set<string>> A(n);
	for (int i = 0, m; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			string s; cin >> s;
			A[i].insert(s);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int c = 0;
			for (auto s : A[i]) {
				c += A[j].count(s);	
			}
			res += (c >= k);
		}
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

