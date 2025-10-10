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

const int MAX = 1e6+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(set<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.emplace(divi[n]);
}

int solve() {
	int n; cin >> n;
	map<int, int> apar, cont, f;

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x == 1) continue;
		set<int> s;
		fact(s, x);

		if (apar[x] == 0) {
			for (int j : s) {
				if (--f[cont[j]] == 0) f.erase(cont[j]);
				f[++cont[j]]++;
			}
		} else {
			for (int j : s) {
				if (--f[cont[j]] == 0) f.erase(cont[j]);
				f[--cont[j]]++;
			}
		}
		cout << f.rbegin()->f << endl;
		apar[x] ^= 1;	
	}

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
