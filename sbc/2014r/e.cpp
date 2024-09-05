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
typedef pair<int, int> ii;

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> mp(n, vector<int>(n));
	for (auto& l : mp) {
		for (auto& c : l) {
			cin >> c;
		}
	}
	// na real acho que vou ter que gerar todas strings quarternarias de tamanho m-1, tomando cuidado pra
	// nao usar as que contam a mesma celula duas vezes. dai eu acho que gera todos os componentes conexos
	// dai acho que a complexidade fica (4^9*n*n), que eh 3e9 no pior caso. com tle 8s talvez passe.

	vector<set<ii>> formatos;
	vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < n;
	};

	function<void(set<ii>, int, int, int)> f = [&](set<ii> v, int i, int j, int k) {
		if (k > m) return;
		if (v.size() == m) { formatos.push_back(v); return; }

		for (auto mov : movs) {
			int ni = i + mov.f, nj = j + mov.s; 

			if (!valido(ni, nj)) continue;
			if (v.count(ii(ni, nj))) continue;
			v.emplace(ni, nj);
			f(v, ni, nj, k+1);
			f(v, i, j, k+1);
			v.erase(ii(ni, nj));
		}
	};
	set<ii> origem; origem.emplace(0, 0);
	f(origem, 0, 0, 0);

	//for (auto& s : formatos) {
	//	vector<vector<int>> vis(m, vector<int>(m, 0));
	//	for (auto& [i, j] : s) {
	//		//cout << '(' << i << ", " << j << ')' << ", ";
	//		vis[i][j] = 1;	
	//	}
	//	for (auto l : vis) { for (auto c : l) cout << c; cout << endl; }
	//	cout << endl;
	//}

	auto soma = [&](int i, int j, set<ii>& s) {
		int res = 0;
		for (auto& [dx, dy] : s) {
			if (!valido(i+dx, j+dy)) return 0;	
			res += mp[i+dx][j+dy];
		}
		return res;
	};

	// para cada posicao, checar todos os componentes conexos de tamanho m;
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (auto& k : formatos) {
				res = max(res, soma(i, j, k));
			}
		}
	};
	cout << res << endl;

    return(0);
}
