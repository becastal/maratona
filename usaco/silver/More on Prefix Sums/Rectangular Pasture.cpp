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
const int MAX = 2510;

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	int n; cin >> n;
	vector<pair<int, int>> v(n);
	map<int, int> X, Y;

	for (auto& [x, y] : v) cin >> x >> y;

	sort(v.begin(), v.end());
	int ii = 1;
	for (auto [x, y] : v) X[x] = ii++;

	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.s < b.s;
	});
	ii = 1;
	for (auto [x, y] : v) Y[y] = ii++;

	vector<vector<ll>> pre(MAX, vector<ll> (MAX));
	for (auto& [x, y] : v) {
		x = X[x], y = Y[y];
		pre[x][y]++;
		pre[x+1][y]--;
		pre[x][y+1]--;
		pre[x+1][y+1]++;
	}

	for (int ii = 0; ii < 2; ii++) {
		for (int i = 1; i < MAX; i++) {
			for (int j = 1; j < MAX; j++) {
				pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			}
		}
	}

	auto query = [&](int x1, int y1, int x2, int y2) {
		return pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1];
	};

	sort(v.begin(), v.end());
	ll res = n + 1;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int x1 = v[i].f, x2 = v[j].f;
			int y1 = min(v[i].s, v[j].s), y2 = max(v[i].s, v[j].s);
			
			ll abaixo = 1 + query(x1, 1, x2, y1-1);
			ll acima = 1 + query(x1, y2+1, x2, n);
			//cout << "(" << i << ", " << j << "): [" << x1 << ", " << y1 << "], [" << x2 << ", " << y2 << "]" << endl; cout << "aci = " << acima << ", aba = " << abaixo << endl;
			res += abaixo * acima;
		}
	}

	cout << res << endl;

    return(0);
}
