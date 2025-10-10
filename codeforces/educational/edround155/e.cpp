#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    //_;

	int n; cin >> n;
	
	vector<int> pai(n, -1);

	vector<vector<int>> g(n);
	for (int i = 1; i < n; i++) {
		cin >> pai[i]; pai[i]--;
		g[i].push_back(pai[i]);
		g[pai[i]].push_back(i);
	}

	int max_prof = 0;
	function<void(int, int, int)> dfs_prof = [&](int u, int pai, int prof) {
		max_prof = max(max_prof, prof);	

		for (int v : g[u]) {
			if (v == pai) continue;
			dfs_prof(v, u, prof+1);
		}
	};
	dfs_prof(0, -1, 0);

	if (max_prof == 1) {
		cout << 1 << endl;

		for (int i = 1; i < n; i++) {
			cout << 1 << " \n"[i==n-1];
		}

		int est;
		while (cin >> est and !est) {
			int x; cin >> x;
			cout << 1 << endl;
		}
	} else if (max_prof == 2) {
		cout << 2 << endl;

		vector<int> cor(n, -1);
		function<void(int, int)> dfs_cor = [&](int u, int c) {
			cor[u] = c;

			for (int v : g[u]) if (cor[v] == -1) {
				dfs_cor(v, !c);
			}
		};
		dfs_cor(0, 0);

		for (int i = 1; i < n; i++) {
			cout << cor[i]+1 << " \n"[i==n-1];
		}

		int est;
		while (cin >> est and !est) {
			vector<int> agr(2);
			for (int& i : agr) cin >> i;

			if (!agr[0]) {
				cout << 2 << endl;
			} else if (!agr[1]) {
				cout << 1 << endl;
			} else {
				cout << 2 << endl;
			}
		}
	} else {
		cout << 3 << endl;

		vector<int> cor(n, -1);
		function<void(int, int)> dfs_cor = [&](int u, int c) {
			c %= 3;
			cor[u] = c;

			for (int v : g[u]) if (cor[v] == -1) {
				dfs_cor(v, c+1);
			}
		};
		dfs_cor(0, 0);

		for (int i = 1; i < n; i++) {
			cout << cor[i]+1 << " \n"[i==n-1];
		}

		int est;
		while (cin >> est and !est) {
			vector<int> agr(3);
			for (int& i : agr) cin >> i;

			if (!agr[0] + !agr[1] + !agr[2] == 2) {
				cout << (agr[0] ? 1 : (agr[1] ? 2 : 3)) << endl;	
				continue;
			}

			if (!agr[0]) {
				cout << 2 << endl;
			} else if (!agr[1]) {
				cout << 3 << endl;
			} else if (!agr[2]) {
				cout << 1 << endl;
			} else {
				assert(0);
			}
		}
	}


    return(0);
}
