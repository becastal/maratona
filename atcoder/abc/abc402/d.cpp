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

int main()
{
    _;

	int n, m; cin >> n >> m;
	
	vector<ll> cont(n, 0);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		cont[(a + b) % n]++;
	}

	ll res = (ll)m * (m - 1) / 2;
	for (ll i : cont) {
		res -= i * (i - 1) / 2;
	}
	cout << res << endl;

    return(0);
}
