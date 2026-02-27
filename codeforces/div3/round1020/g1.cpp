#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

#ifdef LOCAL
struct It {
	int n, root;
	vector<vector<int>> G;
	vector<int> Val, F;

	It() {
		n = 5;
		G = vector<vector<int>>(n);
		F = vector<int>(n);
		Val = vector<int>(n);

		for (int i = 0; i < n; i++) {
			Val[i] = F[i] = uniform(0, 1) ? +1 : -1;
		}

		for (int i = 1; i < n; i++) {
			G[i].push_back(0);
			G[0].push_back(i);
		}
		root = uniform(0, n-1);

		function<void(int, int)> dfs = [&](int u, int p) {
			F[u] += Val[u];
			for (int v : G[u]) if (v != p) {
				F[v] += F[u];
				dfs(v, u);
			}
		};
		dfs(root, -1);
	}

	int query1(vector<int> V) {
		int res = 0;
		for (int i : V) {
			res += F[i];
		}
		return res;
	}

	int query2(int u) {
		Val[u] *= -1;
		filL(all(F), 0);
		function<void(int, int)> dfs = [&](int u, int p) {
			F[u] += Val[u];
			for (int v : G[u]) if (v != p) {
				F[v] += F[u];
				dfs(v, u);
			}
		};
		dfs(root, -1);
	}

	void printa(vector<int> V) {
		assert(V == Val);
	}
};
#else
struct It {
	int n;
	vector<vector<int>> G;

	It() {
		cin >> n;
		G = vector<vector<int>>(n);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v; u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}

	int query1(vector<int> V) {
		int k = (int)V.size();
		cout << "? 1 " << k;
		for (int i : V) {
			cout << " " << i + 1;
		}
		cout << endl;
		int res; cin >> res;
		return res;
	}

	void printa(vector<int> V) {
		cout << "!";
		for (int i : V) {
			cout << " " << i;
		}
		cout << endl;
	}
};
#endif

int solve() {
	It I;

	int x = I.query1(0);
	I.query2(0);
	int y = I.query1(0);


	for (int i = 1; i < n; i++) {
		
	}

	return(0);
}

signed main()
{
    //_;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

