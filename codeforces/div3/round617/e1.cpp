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
	string s; cin >> s;

	vector<vector<int>> g(n);
	for (int i = 1; i < n; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (s[i] < s[j]) {
				//swap(s[i], s[j]);
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

	vector<int> cor(n, -1);
	function<bool(int, int)> dfs = [&](int u, int c) {
		cor[u] = c;
		for (int v : g[u]) {
			if (cor[v] == -1) {
				if (!dfs(v, !c)) {
					return 0;
				}
			}
			else if (cor[v] == c) return 0;
		}
		return 1;
	};

	int ok = 1;
	for (int i = 0; i < n and ok; i++) {
		if (cor[i] == -1) ok &= dfs(i, 0);		
	}

	if (!ok) return cout << "NO" << endl, 0;

	cout << "YES" << endl;
   	for (int i : cor) cout << i; cout << endl; 

    return(0);
}
