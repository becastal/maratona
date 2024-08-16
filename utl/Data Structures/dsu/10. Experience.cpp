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

struct UF {
	vector<int> id, sz, exp, sobra;
	UF(int n) : id(n), sz(n, 1), exp(n, 0), sobra(n, 0) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return id[i] == i ? i : id[i] = find(id[i]);
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		sobra[j] = exp[i];
	}

	void add(int i, int x) {
		exp[find(i)] += x;
	}

	int get(int i) {
		int res = exp[i];
		if (i == id[i]) {
			return res;
		}

		res += get(id[i]) - sobra[i];
		return res;
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m;
	UF dsu(n);

	for (int i = 0; i < m; i++) {
		string qi; cin >> qi;
		if (qi == "join") {
			int x, y; cin >> x >> y; x--, y--;
			dsu.merge(x, y);
		} else if (qi == "add") {
			int x, y; cin >> x >> y; x--;
			dsu.add(x, y);
		} else if (qi == "get") {
			int x; cin >> x; x--;
			cout << dsu.get(x) << endl;
		}
	}
    
    return 0;
}

