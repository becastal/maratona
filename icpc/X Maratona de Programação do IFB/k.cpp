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

const int MAX = 2e7+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(set<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.insert(divi[n]);
}

int solve() {
	int n, xs; cin >> n >> xs;
	set<int> ps;
	fact(ps, xs);

	int res = -INF, pos = 0; 
	for (int i = 0, x; i < n; i++) {
		cin >> x;

		set<int> a;
		fact(a, x);

		int agr = 0;
		for (int i : a) {
			if (i != 1) agr += !ps.count(i);
		}

		if (agr > res) {
			res = agr;
			pos = i;
		}
	}
	
	cout << pos + 1 << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
