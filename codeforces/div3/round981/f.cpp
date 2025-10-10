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
	ll n, k; cin >> n >> k;
	n %= mod;
	
	int a = 1 % k, b = 1 % k, t = 1;

	while (a) {
		t++;
		tie(a, b) = tuple(b, (a + b) % k);
	}

	cout << n * t % mod << endl;
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
