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

int main()
{
    _;
	setIO("");

	int n, m, r; cin >> n >> m >> r;
	vector<int> v(n), b(r);
	vector<pair<int, int>> a(n);
	
	for (int& i : v) cin >> i;
	for (auto& [p, q] : a) cin >> q >> p;
	for (int& i : b) cin >> i;

	sort(v.rbegin(), v.rend());
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), a.rend());

	for (int i = 0, l = 0, r = 0; i < n; i++) {
		int quant = v[i], vendido = 0, ult = 0;
		
		
		while (l < m) {
			auto& [p, q] = a[l];
			int tira = min(quant, q);
			vendido += tira * p;
			quant -= tira, q -= tira;

			if (quant) l++;
		}
	}

    return(0);
}
