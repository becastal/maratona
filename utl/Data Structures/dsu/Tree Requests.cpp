#include <bits/stdc++.h>
// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Bit {
	int n;
	vector<int> F;

	Bit(int n_) : n(n_), F(n_+1, 0) {}
	void update(int i, int x) {
		for (++i; i <= n; i+=i&-i) F[i] += x;	
	}
	int pref(int i) {
		int res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	}
	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int palindromo(vector<int>& C) {
	int imp = 0, tot = 0;
	for (int i : C) {
		imp += (i & 1);
		tot += i;
	}

	if (tot & 1) return imp == 1;
	return !imp;
}

int solve() {
	int n, q; cin >> n >> q;

	vector<vector<int>> G(n);
	for (int i = 1, p; i < n; i++) {
		cin >> p; p--;
		G[i].push_back(p);
		G[p].push_back(i);
	}
	string S; cin >> S;

	int t = 0;
	vector<int> L(n), R(n);
	vector<vector<int>> D(n+1);
	function<void(int, int, int)> dfs = [&](int u, int p, int d) {
		D[d].push_back(u);
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			dfs(v, u, d + 1);
			
		}
		R[u] = t-1;
	};
	dfs(0, -1, 1);

	vector<vector<array<int, 2>>> Q(n+1);
	for (int i = 0, u, d; i < q; i++) {
		cin >> u >> d; u--;
		Q[d].push_back({u, i});
	}

	vector<int> Rr(q);
	vector<Bit> bit(26, Bit(n));
	for (int d = 1; d <= n; d++) {
		for (int u : D[d]) {
			bit[S[u] - 'a'].update(L[u], +1);
		}

		for (auto [u, id] : Q[d]) {
			vector<int> cont(26, 0);				
			for (int i = 0; i < 26; i++) {
				cont[i] = bit[i].query(L[u], R[u]);
			}
			Rr[id] = palindromo(cont);
		}

		for (int u : D[d]) {
			bit[S[u] - 'a'].update(L[u], -1);
		}
	}

	for (int i : Rr) {
		cout << (i ? "Yes" : "No") << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

