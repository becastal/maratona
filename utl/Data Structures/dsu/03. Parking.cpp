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
		id[i] = j;
	}
};

int main()
{
    _;

	int n; cin >> n;
	UF dsu(n);
	vector<int> v(n);
	for (int& i : v) cin >> i, i--;

	for (int i : v) {
		i = dsu.find(i);
		cout << i + 1 << ' ';		
		int prox = (i + 1 < n ? i + 1 : 0);
		dsu.merge(i, prox);
	}
	cout << endl;
    
    return(0);
}
