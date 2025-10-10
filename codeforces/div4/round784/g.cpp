#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));

	for (auto& i : v) for (auto& j : i) cin >> j;

	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '*') {
				int ii = i;
				while (ii + 1 < n and v[ii+1][j] == '.') {
					v[ii][j] = '.';
					v[ii+1][j] = '*';
					ii++;
				}
			}
		}
	}

	for (auto& i : v) {
		for (auto& j : i) cout << j;
		cout << endl;
	}
	cout << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
