#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);

	for (auto& i : A) {
		cin >> i;
	}

	vector<vector<int>> nao(n, vector<int>(m));
	auto ruim = [](char c) {
		return c == '#' or c == '>' or c == '<' or c == '^' or c == 'v';
	};

	for (int i = 0; i < n; i++) {
		for (int l = 0, r; l < m; l = r) {
			r = l + 1;
			if (A[i][l] != '>') continue;

			while (r < m and !ruim(A[i][r])) {
				r++;
			}
			
			for (int j = l; j < r; j++) {
				nao[i][j] = 1;				
			}
		}

		for (int l = m-1, r; l >= 0; l = r) {
			r = l - 1;
			if (A[i][l] != '<') continue;

			while (r >= 0 and !ruim(A[i][r])) {
				r--;
			}
			
			for (int j = l; j >= max(0, r); j--) {
				nao[i][j] = 1;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		for (int l = 0, r; l < n; l = r) {
			r = l + 1;
			if (A[l][j] != 'v') continue;

			while (r < n and !ruim(A[r][j])) {
				r++;
			}
			
			for (int i = l; i < r; i++) {
				nao[i][j] = 1;
			}
		}

		for (int l = n-1, r; l >= 0; l = r) {
			r = l - 1;
			if (A[l][j] != '^') continue;

			while (r >= 0 and !ruim(A[r][j])) {
				r--;
			}
			
			for (int i = l; i >= max(0, r); i--) {
				nao[i][j] = 1;
			}
		}
	}

	int ini, inj, outi, outj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 'S') {
				ini = i, inj = j;
			} else if (A[i][j] == 'G') {
				outi = i, outj = j;
			}
		}
	} vector<vector<int>> D(n, vector<int>(m, -1)); D[ini][inj] = 0;
	queue<array<int, 2>> Q; Q.push({ini, inj});

	const vector<array<int, 2>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	const auto valido = [&](int i, int j) { 
		return i >= 0 and i < n and j >= 0 and j < m and !ruim(A[i][j]) and !nao[i][j];
	};
	while (Q.size()) {
		auto [ui, uj] = Q.front(); Q.pop();

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;
			if (valido(vi, vj) and D[vi][vj] == -1) {
				D[vi][vj] = D[ui][uj] + 1;
				Q.push({vi, vj});
			}
		}
	}

//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << int(nao[i][j] or ruim(A[i][j])) << " \n"[j==m-1];
//		}
//	}

	cout << D[outi][outj] << endl;

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

