#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve(int n1, int n2, int d) {
	vector<stack<int>> Livres(2);
	vector<vector<int>> G(n1 + n2);
	for (int i = 0, a, b; i < d; i++) {
		cin >> a >> b; a--, b--;
		G[a].push_back(b);
	}

	auto tenta = [&](int inicio) {
		vector<int> In(n1 + n2);
		for (int i = 0; i < n1 + n2; i++) {
			for (int j : G[i]) {
				In[j]++;
			}
		}

		for (int i = 0; i < n1 + n2; i++) if (!In[i]) {
			Livres[i < n1].push(i);
		}

		int cont = 0;
		for (int foi = 0, p = inicio; foi < n1 + n2; p ^= 1) {
			while (Livres[p].size()) {
				int u = Livres[p].top(); Livres[p].pop();
				foi++;

				for (int v : G[u]) {
					if (--In[v] == 0) {
						Livres[v < n1].push(v);
					}
				}
			}
			cont++;
		}

		return cont + 1;	
	};
	cout << min(tenta(0), tenta(1)) << endl;

	return(0);
}

signed main()
{
    _;

	int n1, n2, d; //cin >> t;
	while (cin >> n1 >> n2 >> d and (n1 or n2 or d)) {
		solve(n1, n2, d);
	}
    
    return(0);
}

