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
	vector<int> id, sz, bip, c;

	UF(int n) : id(n), sz(n, 1), bip(n, 1), c(n) { 
		iota(id.begin(), id.end(), 0); 
	}

	int find(int a) { return a == id[a] ? a : find(id[a]); }
	int color(int a) { return a == id[a] ? c[a] : c[a] ^ color(id[a]); }

	void merge(int a, int b) {
		bool change = color(a) == color(b);
		a = find(a), b = find(b);
		if (a == b) {
			if (change) bip[a] = 0;
			return;
		}
		
		if (sz[a] < sz[b]) swap(a, b);
		if (change) c[b] = 1;
		sz[a] += sz[b], id[b] = a, bip[a] &= bip[b];
	}
};

int main()
{
    _;

	int n, m, shift = 0; cin >> n >> m;
	UF dsu(n);

	for (int i = 0, qi, a, b; i < m; i++) {
		cin >> qi >> a >> b;
		a--, b--;
		int x = (a + shift) % n;
		int y = (b + shift) % n;
		if (!qi) {
			dsu.merge(x, y);
		} else {
			if (dsu.color(x) == dsu.color(y)) {
				cout << "YES" << endl;
				shift = (shift + 1) % n;
			} else {
				cout << "NO" << endl;
			}
		}
	}
    
    return(0);
}
