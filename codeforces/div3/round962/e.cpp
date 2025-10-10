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
const int mod = 1e9 + 7;

void solve() {
    string s; cin >> s;
    int n = (int) s.size();
	
	vector<int> p(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		p[i] = p[i-1] + (s[i-1] == '1' ? 1 : -1);
	}

	map<int, ll> cont;
	ll res = 0;

	for (int i = 0; i <= n; i++) {
		res = (res + (n - i + 1) * cont[p[i]]) % mod;
		cont[p[i]] = (cont[p[i]] + (i + 1)) % mod;
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
