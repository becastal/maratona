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

int solve() {
	ll n, m; cin >> n >> m;
	n /= m;

	vector<int> ciclo;
	for (int i = 0; i < 10; i++) {
		ciclo.push_back((i + 1) * m % 10);
	}

	ll res = 0;
	for (int i = 0; i < n % 10; i++) {
		res += ciclo[i];
	}

	cout << res + n / 10 * accumulate(ciclo.begin(), ciclo.end(), 0LL) << endl;

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
