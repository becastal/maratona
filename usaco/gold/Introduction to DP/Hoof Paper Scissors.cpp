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

int self_max(int& a, int b) {
	return a = max(a, b);
}

int main()
{
    _;
	setIO("hps");

	int n, K; cin >> n >> K;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == 'H') v[i] = 0;
		if (c == 'P') v[i] = 1;
		if (c == 'S') v[i] = 2;
	}

	vector dp(n + 1, vector<array<int, 3>> (K + 2, {0, 0, 0}));
	// dp[i][j][k]: total de pontos tendo feito i jogadas, j trocas e jogado k por ultimo

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < 3; k++) {
				// ganho se (k + 2) % 3  == v[i]
				if ((k + 2) % 3 == v[i]) dp[i][j][k]++;

				// todas as trocas:
				for (int l = 0; l < 3; l++) {
					self_max(dp[i+1][j+1][l], dp[i][j][k]);
				}

				// nao trocar
				self_max(dp[i+1][j][k], dp[i][j][k]);
			}
		}
	}

	int res = 0;
	for (int j = 0; j <= K; j++) {
		for (int k = 0; k < 3; k++) {
			res = max(res, dp[n][j][k]);
		}
	}

	cout << res << endl;

    return(0);
}

