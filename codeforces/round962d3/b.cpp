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
	int n, k; 
	cin >> n >> k;
	int m = n / k;
	vector<vector<char>> v(n, vector<char>(n)), 
						res(m, vector<char>(m));

	for (auto& l : v) for (auto& c : l) cin >> c;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			res[i][j] = v[i*k][j*k];
		}
	}

	for (auto& l : res) {
		for (auto& c : l) {
			cout << c;
		}
		cout << endl;
	}
}

int main() {
    _;

	int t; 
	cin >> t;
	while (t--) {
		solve();
	}
    
    return 0;
}

