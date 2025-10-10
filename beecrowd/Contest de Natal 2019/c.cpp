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

int main()
{
    _;

	int n; cin >> n;
	map<string, vector<pair<string, int>>> g;
	map<string, int> indeg, p, naocomp;

	int cont = 0;
	for (int i = 0, pi; i < n; i++) {
		string si; cin >> si >> pi;
		indeg[si] = 0;
		naocomp[si] = 1;
		p[si] = pi;
	}

   	string p1, p2;
	int q;
	while (cin >> p1 >> p2 >> q) {
		g[p2].emplace_back(p1, q);	
		indeg[p1]++;		
	}

	auto topo = [&]() {
		queue<string> q;

		for (auto [si, deg] : indeg) {
			if (!deg) q.push(si);
		}

		while (q.size()) {
			string u = q.front(); q.pop();

			for (auto [v, quant] : g[u]) {
				p[v] += p[u] * quant;

				if (--indeg[v] == 0) q.push(v);
			}
		}
	};
	topo();

	for (auto [si, v] : g) {
		if (!naocomp.count(si)) cout << si << ' ' << p[si] << endl;
	}
		
    return(0);
}
