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
	vector<int> id, sz;
	UF(int n) : id(n), sz(n, 1) {
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

	int n, q; cin >> n >> q;
	UF dsu(n);
	while (q--) {
		int ti, ui, vi; 
		cin >> ti >> ui >> vi; 
		if (!ti) {
			dsu.merge(ui, vi);
		} else {
			cout << (dsu.find(ui) == dsu.find(vi) ? 1 : 0) << endl;
		}
	}
    
    return(0);
}
