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

void solve() {
	ll n, m, r, c; 
	cin >> n >> m >> r >> c; 

	ll res = 0;

	// todos que movem pro lado;
	res += (n - r) * (m - 1) + (m - c);

	// todos que tem que trocar de linha
	res += (n - r) * m;

	//cout << res << endl;
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
