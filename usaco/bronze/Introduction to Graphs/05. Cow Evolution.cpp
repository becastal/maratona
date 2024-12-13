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
	setIO("evolution");

	int n; cin >> n;

	map<string, vector<string>> g;
	for (int i = 0, k; i < n; i++) {
		cin >> k;
		vector<string> vs;
		for (int j = 0; j < k; j++) {
			string s; cin >> s;
			vs.push_back(s);	
		}

		for (int j = 1; j < k; j++) {
			g[vs[j-1]].push_back(vs[j]);		
			g[vs[j]].push_back(vs[j-1]);		
		}
	}

	map<string, int> vis;
	auto dfs = [&](string in) {
		map<string, int> visagr;
		visagr[in] = 1, vis[in] = 1;
		stack<string> st;
		st.push(in);	

		while (st.size()) {
			string u = st.top(); st.pop();	

			for (string& v : g[u]) {
				if (!vis[v]) {
					vis[v] = 1, visagr[v] = 1;
					st.push(v);
				} else if (!visagr[v]) {
					return 1;
				}
			}
		}
		return 0;
	};

	for (auto [s, vs] : g) {
		if (vis[s]) continue;

		if (dfs(s)) return cout << "no" << endl, 0;
	}

	cout << "yes" << endl;

    return(0);
}
