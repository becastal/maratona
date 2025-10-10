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
	int n; cin >> n;
	ll x, y; cin >> x >> y;

	ll soma = 0;
	vector<int> v(n);
	for (int& i : v) cin >> i, soma += i;
	sort(v.begin(), v.end());

	ll res = 0;
	// bin pra achar maior r em que soma - v[l] - v[r] >= x e <= y

    for (int l = 0; l < n; l++) {
        ll v_r1 = soma - v[l] - y;
        ll v_r2 = soma - v[l] - x;

        int r1 = lower_bound(v.begin() + l + 1, v.end(), v_r1) - v.begin();
        int r2 = upper_bound(v.begin() + l + 1, v.end(), v_r2) - v.begin() - 1;

        if (r1 <= r2 and r1 < n and r2 >= 0) {
            res += r2 - r1 + 1;
        }
    }

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
