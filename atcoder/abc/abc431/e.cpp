#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	primeira ideia eh bb, mas me parece dificil testar algum mid.

	talvez bfs01 resolva. pra uma posicao (i, j), eu posso simplesmente
	seguir aquela direcao pagando 0 ou mudar ela pagando 1 e vendo pra
	onde isso me leva.

	mas isso pode levar a um problema porque eu posso repassar por celulas
	em que eu teria pagado pra mudar.

	mas mesmo assim, num caminho otimo nao parece que eu teria que passar 
	varias vezes pela mesma celula.

	alias, eu nunca passaria pela mesma celula com a mesma direcao duas vezes.
	da pra guardar entao dis[n][4]. bfs01 nisso? res en dis[n][direita].
	o foda seria "lembrar" mudancas.

*/

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<array<int, 2>> movs = {
		{-1, 0},
		{1, 0},
		{0, 1},
		{0, -1}
	};

	auto t = [&](array<int, 2> b, char c) -> array<int, 2> {
		array<int, 2> a = b;
		if (c == 'A') return a;
		swap(a[0], a[1]);
		if (c == 'C') {
			a[0] *= -1, a[1] *= -1;
		}
		return a;
	};
	auto id = [&](array<int, 2>& a) -> int {
		if (a[0]) return a[0] > 0;
		return 2 + (a[1] < 0);
	};
	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m;	
	};

	const int INF = n * m + 10;
	vector<vector<vector<int>>> D(n, vector<vector<int>>(m, vector<int>(4, INF)));
	deque<array<int, 3>> Q;
	Q.push_front({0, 0, 2});
	D[0][0][2] = 0;

	while (Q.size()) {
		auto [ui, uj, dirid] = Q.front(); Q.pop_front();
		int du = D[ui][uj][dirid];

		for (char c : {'A', 'B', 'C'}) {
			int w = (c != A[ui][uj]);

			array<int, 2> dir_ = t(movs[dirid], c);
			auto [di, dj] = dir_;
			int vi = ui + di, vj = uj + dj;
			int dir_id = id(dir_);

			if (!valido(vi, vj)) continue;
			if (du + w < D[vi][vj][dir_id]) {
				D[vi][vj][dir_id] = du + w;
				if (w) {
					Q.push_back({vi, vj, dir_id});
				} else {
					Q.push_front({vi, vj, dir_id});
				}
			}
		}
	}

	array<int, 2> dir = movs[2];
	int res = INF;
	for (int i = 0; i < 4; i++) {
		if (D[n-1][m-1][i] == INF) continue;
		for (char c : {'A', 'B', 'C'}) {
			auto out = t(movs[i], c);
			if (out == dir) {
				int w = (c != A[n-1][m-1]);
				res = min(res, D[n-1][m-1][i] + w);
			}
		}
	}
	cout << res << endl;
	

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}


