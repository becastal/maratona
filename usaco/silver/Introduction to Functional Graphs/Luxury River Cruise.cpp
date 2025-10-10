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
	setIO("cruise");

	int n, m, k; cin >> n >> m >> k;
	
	vector<array<int, 2>> g(n);
	for (auto& [l, r] : g) cin >> l >> r, l--, r--;

	vector<char> movs(m);
	for (auto& i : movs) cin >> i;

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		int u = i;
		for (int j = 0; j < m; j++) {
			u = g[u][movs[j] == 'R'];
		}

		p[i] = u;	
	}

	vector<int> vis(n, 0);
	int u = 0, cont = 0;

	while (1) {
		u = p[u];
		cont++;

		if (cont == k) return cout << u + 1 << endl, 0;
		if (vis[u]) break;
		vis[u] = 1;
	}

	vector<int> ciclo = {u};
	for (int u_ = p[u]; u_ != u; u_ = p[u_]) {
		ciclo.push_back(u_);
	}
	k -= cont;
	int nn = (int)ciclo.size();
	
	cout << ciclo[(k % nn + nn) % nn] + 1 << endl;

    return(0);
}
