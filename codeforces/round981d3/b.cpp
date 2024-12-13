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
	int n; cin >> n;

	vector<vector<int>> v(n, vector<int>(n));
	for (auto& l : v) for (auto& c : l) cin >> c;

	map<int, int> M;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] < 0) 
			M[i-j] = max(M[i-j], abs(v[i][j]));
		}
	}

	int res = 0;
	for (auto [a, b] : M) {
		res += b;
	}
	cout << res << endl;
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
