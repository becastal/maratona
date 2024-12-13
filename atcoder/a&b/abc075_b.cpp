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

	int n, m; cin >> n >> m;
	vector<vector<char>> M(n, vector<char>(m));
	for (auto& l : M) for (auto& c : l) cin >> c;

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m;
	};

	vector<pair<int, int>> movs = {
		{1, 0},
		{0, 1},
		{-1, 0},
		{0, -1},
		{-1, -1},
		{1, -1},
		{-1, 1},
		{1, 1}
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (M[i][j] == '#') {
				cout << '#';
				continue;
			}
			int agr = 0;
			for (auto mov : movs) {
				if (valido(i + mov.f, j + mov.s)) {
					agr += M[i + mov.f][j + mov.s] == '#';
				}
			}
			cout << agr;
		}
		cout << endl;
	}
    
    return(0);
}
