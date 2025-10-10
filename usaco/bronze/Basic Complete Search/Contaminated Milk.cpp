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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("badmilk");

	int n, m, d, s; cin >> n >> m >> d >> s;

	vector<vector<tuple<int, int, int>>> ev(110);
	for (int i = 0, p, mi, t; i < d; i++) {
		cin >> p >> mi >> t;	
		ev[t].emplace_back(0, p, mi);
	}

	for (int i = 0, p, t; i < s; i++) {
		cin >> p >> t;
		ev[t].emplace_back(1, p, -1);
	}

	int res = -INF;
	for (int i = 1; i <= m; i++) {
		vector<vector<int>> tomou(n+1, vector<int>(m+1, 0));
		int ok = 1;
		for (int t = 0; t < 110; t++) {
			for (auto [tp, p, mi] : ev[t]) {
				if (tp == 1) ok &= (tomou[p][i] == 1);
			}
			for (auto [tp, p, mi] : ev[t]) {
				if (tp == 0) tomou[p][mi] = 1;
			}
		}

		if (!ok) continue;
		int agr = 0;
		for (int j = 1; j <= n; j++) {
			agr += tomou[j][i];
		}
		res = max(res, agr);
	}
	cout << res << endl;
	
    return(0);
}
