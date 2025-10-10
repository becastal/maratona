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

const int MAX = 1e7+10;
int res[MAX], memo[MAX];

int solve() {
	int n; cin >> n;
	map<int, int> a;
	memset(res, -1, sizeof(res));
	memset(memo, 0, sizeof(memo));

	for (int i = 0, ai; i < n; i++) {
		cin >> ai;
		res[ai] = (i + 1);
	}

	int m; cin >> m;
	while (m--) {
		int x, agr = -1; cin >> x;
		if (memo[x] != 0) {
			cout << memo[x] << endl;
			continue;
		}

		for (int i = x; i < MAX; i += x) {
			if (res[i] != -1) agr = res[i];
		}
		memo[x] = agr;
		cout << agr << endl;
	}

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
