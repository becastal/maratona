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
	setIO("");

	vector<int> t(110, 0);
	int n, m; cin >> n >> m;
	for (int i = 0, l, r, ci; i < n; i++) {
		cin >> l >> r >> ci;
		for (int j = l; j <= r; j++) {
			t[j] = max(t[j], ci);
		}
	}

	vector<tuple<int, int, int, int>> a(m);
	for (auto& [l, r, pi, mi] : a) cin >> l >> r >> pi >> mi;

	int res = INF;
	for (int i = 0; i < (1 << m); i++) {
		int preco = 0;

		vector<int> ti(110, 0);
		for (int j = 0; j < m; j++) {
			if (!(i & (1 << j))) continue;
			auto [l, r, pi, mi] = a[j];
			preco += mi;
			for (int k = l; k <= r; k++) {
				ti[k] += pi;
			}
		}

		int ok = 1;
		for (int j = 0; j < 110; j++) {
			ok &= ti[j] >= t[j];
		}
		if (ok) res = min(res, preco);
	}
	cout << res << endl;

    return(0);
}
