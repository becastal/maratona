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
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<char> cc = {'R', 'G', 'B'};
	vector<string> pad(3, "");

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < k; i++) {
			pad[j].push_back(cc[(i + j) % 3]);
		}
	}

	vector<vector<int>> pre(n+1, vector<int>(3, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			pre[i][j] = pre[i-1][j] + (s[i-1] != cc[((i-1 + j) % 3)]);
		}
	}

	int res = INF;
	for (int i = 0; i <= n-k; i++) {
		for (int j = 0; j < 3; j++) {
			res = min(res, pre[i+k][j] - pre[i][j]);
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
