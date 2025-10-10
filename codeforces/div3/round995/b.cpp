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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll res = (n / (a+b+c)) * 3;
    n %= (a+b+c);

    vector<ll> v = {a, b, c};

    ll i = 0;
    while (n > 0) {
        n -= v[i % 3];
        i++;
    }

    cout << res + i << endl;
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
