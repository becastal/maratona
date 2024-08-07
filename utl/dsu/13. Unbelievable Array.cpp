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
	vector<int> id;
	UF(int n) : id(n) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		id[i] = j;
	}
};

void solve() {
	int n, q; cin >> n >> q;
	vector<int> v(n);
	UF dsu((int) 1e6 + 10);

	for (int& i : v) cin >> i;
	while (q--) {
		int qi; cin >> qi;	
		if (qi == 1) {
			int x, y; cin >> x >> y; x--, y--;
			dsu.merge(x, y);
		} else {
			int idx; cin >> idx;
			cout << dsu.find(v[idx]) + 1 << endl;
		}
	}
}

int main()
{
    _;

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ":" << endl;
		solve();
	}
    
    return(0);
}
