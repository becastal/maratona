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
	int n, k; cin >> n >> k;

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int b = n, a = i;
		int ok = 1;
		for (int j = 0; j < k - 2; j++) {
			int aux = a;
			a = b - aux;
			b = aux;
			ok &= (a <= b) and (min(a, b) >= 0);
			if (!ok) break;
		}
		res += ok;
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
