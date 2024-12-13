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

struct DSU {
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}
};

int main()
{
    _;

	int n, m, k; cin >> n >> m >> k;
	DSU dsu(k + 4);

	auto dist = [] (array<int, 3> a, array<int, 3> b) {
		return sqrt((a[0] - b[0]) * (a[0] - b[0]) +  (a[1] - b[1]) * (a[1] - b[1]));
	};

	vector<array<int, 3>> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];

		// baixo
		if (v[i][1] + v[i][2] >= n) dsu.merge(0, i + 4);

		// direita
		if (v[i][0] + v[i][2] >= m) dsu.merge(1, i + 4);

		// cima
		if (v[i][1] - v[i][2] <= 0) dsu.merge(2, i + 4);
		
		// esquerda
		if (v[i][0] - v[i][2] <= 0) dsu.merge(3, i + 4);
	}

	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (dist(v[i], v[j]) <= (double) v[i][2] + v[j][2]) {
				dsu.merge(i + 4, j + 4);
			}
		}
	}

	int res = dsu.find(0) == dsu.find(1) or dsu.find(0) == dsu.find(2) or
			  dsu.find(3) == dsu.find(1) or dsu.find(3) == dsu.find(2);
	cout << (res ? 'N' : 'S') << endl;
    
    return(0);
}
