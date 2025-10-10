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
	setIO("pairup");

	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [y, x] : v) cin >> x >> y;
	sort(v.begin(), v.end());

	int l = 0, r = n-1, res = 0;

    while (l < r) {
        auto& [yl, xl] = v[l];
        auto& [yr, xr] = v[r];
        res = max(res, yl + yr);
        
        if (xl == xr) {
            l++, r--;
        } else if (xl > xr) {
            xl -= xr;
            r--;
        } else {
            xr -= xl;
            l++;
        }
    }
    
    if (l == r) {
        auto& [y, x] = v[l];
        res = max(res, 2 * y);
    }
    
    cout << res << endl;

	return(0);
}
