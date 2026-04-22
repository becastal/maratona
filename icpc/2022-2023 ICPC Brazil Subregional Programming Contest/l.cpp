#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<int> C(n);
	for (int& i : C) {
		cin >> i;
	}

	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}

	int t = 0;
	vector<int> E(n), L(n), R(n), Repr(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		E[t] = C[u];
		L[u] = t++;
		for (auto [v, id] : G[u]) if (v != p) {
			Repr[v] = id;
			dfs(v, u);
		}
		R[u] = t - 1;
	};
	dfs(0, -1);

	vector<array<int, 3>> Q(n);
	for (int i = 0; i < n; i++) {
		Q[i] = {L[i], R[i], i};
	}

	const int tam = ceil(sqrt(n)) + 1;
	sort(all(Q), [&](auto& a, auto& b) {
		if (a[0] / tam != b[0] / tam) return a[0] < b[0];
		if (a[0] / tam % 2) return a[1] > b[1];
		return a[1] < b[1];
	});

	vector<int> Tot(n + 1), Cont(n + 1);;
	for (int i = 0; i < n; i++) {
		Tot[C[i]]++;
	}
	
	int res = 0;
	auto add = [&](int i) {
		int c = E[i];
		res -= Cont[c] * (Tot[c] - Cont[c]);
		Cont[c]++;
		res += Cont[c] * (Tot[c] - Cont[c]);
	};
	auto rem = [&](int i) {
		int c = E[i];
		res -= Cont[c] * (Tot[c] - Cont[c]);
		Cont[c]--;
		res += Cont[c] * (Tot[c] - Cont[c]);
	};

	vector<int> Res(n - 1);
	int l = 0, r = -1;
	for (auto [a, b, v] : Q) {
		while (r < b) add(++r);
		while (l > a) add(--l);
		while (l < a) rem(l++);
		while (r > b) rem(r--);
		if (v) {
			Res[Repr[v]] = res;
		}
		//cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		//cout << "v = " << v << endl;
		//cout << "Repr[v] = " << Repr[v] << endl;
		//for (int i = 0; i <= n; i++) if (Tot[i]) {
		//	cout << i << ": " << Cont[i] << endl;
		//}
		//cout << "res = " << res << endl;
	}

	for (int i = 0; i < n - 1; i++) {
		cout << Res[i] << " \n"[i==n-2];
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
