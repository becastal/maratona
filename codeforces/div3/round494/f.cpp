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

const ll P = 69420;
const ll M = 1e9+9;

int solve() {
	int n, res = 0; cin >> n;
	unordered_map<string, int> mp;
	vector<string> a(n);
	for (auto& i : a) {
		cin >> i;
		if (!mp.count(i)) mp[i] = mp.size() + 1;
		res += (int)s.size();
	}
	
    vector<ll> base(n), pre(n + 1);
    base[0] = 1;
    for (int i = 1; i < n; i++) {
        base[i] = base[i - 1] * P % M;
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] * P + mp[a[i-1]]) % M;
    }

    auto hash = [&] (int l, int r) {
        ll h = (pre[r + 1] - base[r - l + 1] * pre[l] % M + M) % M;
        return h;
    };

	// testar todas as subs em nnn
	for (int tam = 1; tam <= n; tam++) {
		for (int i = tam; i <= n; i++) {
				
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
