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

	vector<vector<char>> mp(2 ,vector<char>(n));
	int reg = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == '.') { 
				reg = 1;
			}
		}
	}

	if (!reg) {
		cout << 0 << endl;
		return;
	}

	int res = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (mp[i][j] == '.' and mp[i][j - 1] == '.' and mp[i][j + 1] == '.'
				and mp[!i][j] == '.' and mp[!i][j - 1] == 'x' and mp[!i][j + 1] == 'x') {
				res++;
			}
		}
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
