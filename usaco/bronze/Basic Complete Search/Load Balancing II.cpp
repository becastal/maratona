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

struct pre2d {
	int n, m;
	vector<vector<ll>> pre;

	pre2d(vector<vector<int>> a) : n(a.size()), m(a[0].size()), pre(n+1, vector<ll>(m+1)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				pre[i][j] = a[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			}
		}
	}

	ll query(int i, int j, int ii, int jj) { // 1-based
		return pre[ii][jj] - pre[ii][j-1] - pre[i-1][jj] + pre[i-1][j-1];
	}
};

int main()
{
    _;
	setIO("balancing");

	int n; cin >> n;

	vector<pair<int, int>> A(n);

	vector<int> X, Y;
	for (auto& [x, y] : A) {
		cin >> x >> y;
		X.push_back(x + 1), X.push_back(x - 1); 
		Y.push_back(y + 1), Y.push_back(y - 1); 
	}

	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());
	
	auto Xa = X; auto Ya = Y;
	for (auto [x, y] : A) {
		Xa.push_back(x);
		Ya.push_back(y);
	}

	sort(Xa.begin(), Xa.end()); Xa.erase(unique(Xa.begin(), Xa.end()), Xa.end());
	sort(Ya.begin(), Ya.end()); Ya.erase(unique(Ya.begin(), Ya.end()), Ya.end());
	auto idx = [&](int x) { return lower_bound(Xa.begin(), Xa.end(), x) - Xa.begin(); };
	auto idy = [&](int y) { return lower_bound(Ya.begin(), Ya.end(), y) - Ya.begin(); };

	int nx = Xa.size(), ny = Ya.size();
	vector<vector<int>> a(nx, vector<int>(ny, 0));
	for (auto [x, y] : A) {
		a[idx(x)][idy(y)]++;
	}
	pre2d p(a);

	int res = n;
	for (int x_ : X) {
		for (int y_ : Y) {
			// tem que otimizar aqui
			// comprimir coordenada e dai saber cont[x][y] eh uma query de soma em uma prefix sum 2d

			int xi = idx(x_)-1, yi = idy(y_)-1;
			res = min(res, max({
						(int)p.query(1, 1, xi+1, yi+1), 
						(int)p.query(1, yi+2, xi+1, ny), 
						(int)p.query(xi+2, 1, nx, yi+1), 
						(int)p.query(xi+2, yi+2, nx, ny)})); 
		}
	}
	cout << res << endl;

    return(0);
}
