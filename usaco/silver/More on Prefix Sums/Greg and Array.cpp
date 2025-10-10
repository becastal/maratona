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

	int n, m, q; cin >> n >> m >> q;

	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	vector<tuple<int, int, int>> up(m);
	for (auto& [l, r, d] : up) cin >> l >> r >> d;

	vector<ll> pre(m+2), soma(n+2, 0);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		pre[l]++;
		pre[r+1]--;
	}

	for (int i = 1; i <= m; i++) {
		pre[i] += pre[i-1];

		auto [l, r, d] = up[i-1];
		soma[l] += pre[i] * d;
		soma[r+1] -= pre[i] * d;
	}

	for (int i = 1; i <= n; i++) {
		soma[i] += soma[i-1];
		cout << v[i] + soma[i] << " \n"[i==n];
	}

    return(0);
}
