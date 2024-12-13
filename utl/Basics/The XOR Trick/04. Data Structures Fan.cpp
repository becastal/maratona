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
    vector<int> v(n), pref(n+1, 0), res(2, 0);
    for (int& i : v) cin >> i;
    string s; cin >> s;

    for (int i = 1; i <= n; i++) {
        res[s[i-1] - '0'] ^= v[i-1];
        pref[i] = pref[i-1] ^ v[i-1];
    }

    int S = 0;
    int q; cin >> q;
    while (q--) {
        int qi; cin >> qi;

        if (qi == 1) {
            int l, r; cin >> l >> r;
            S ^= pref[r] ^ pref[l-1];
        } else {
            int g; cin >> g;
            cout << (res[g] ^ S) << ' ';
        }
    }
	cout << endl;
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
