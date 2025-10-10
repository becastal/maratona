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
	vector<vector<char>> M(n, vector<char>(n));
	vector<vector<int>> res(n, vector<int>(n, INF));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		res[i][i] = 0;
		q.emplace(i, i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> M[i][j];
			if (i == j or M[i][j] == '-') continue;
			res[i][j] = 1;
			q.emplace(i, j);
		}
	}

	while (q.size()) {
		auto [a, b] = q.front(); q.pop();

		for (int c = 0; c < n; c++) {
			for (int d = 0; d < n; d++) {
				if (M[c][a] != '-' and M[b][d] != '-' and M[c][a] == M[b][d] and res[c][d] == INF) {
					res[c][d] = res[a][b] + 2;
					q.emplace(c, d);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (res[i][j] == INF ? -1 : res[i][j]) << " \n"[j==n-1];
		}
	}

    return(0);
}


