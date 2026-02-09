#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector A(n, vector<int>(m, 0));
	vector<int> C(n, 0), R;
	
	while (k--) {
		int a, b; cin >> a >> b; a--, b--;
		if (++A[a][b] == 1) {
			if (++C[a] == m) {
				R.push_back(a);
			}
		}
	}

	for (int i : R) cout << i + 1 << ' '; cout << endl;

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

