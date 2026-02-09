#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	int a = INT_MAX, b = INT_MIN, c = INT_MAX, d = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (A[i][j] == '#') {
			a = min(a, i);	
			b = max(b, i);
			c = min(c, j);	
			d = max(d, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (A[i][j] == '.' and i >= a and i <= b and j >= c and j <= d) {
			return cout << i + 1 << ' ' << j + 1 << endl, 0;
		}
	}
	assert(0);

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

