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

void solve() {
	int n, x, y; cin >> n >> x >> y;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	ll res = 0;
	map<ii, int> M;
    for (int i = 0; i < n; i++) {
        int xi = v[i] % x;
        int yi = v[i] % y;

        int falta_x = (x - xi) % x;
        res += M[ii(falta_x, yi)];
        
        M[ii(xi, yi)]++;
    }
	//for (int i = 0; i < n; i++) {
	//	for (int j = i + 1; j < n; j++) {
	//		if ((v[i] + v[j]) % x == 0 and (v[i] - v[j]) % y == 0) res++;
	//	}
	//}

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
