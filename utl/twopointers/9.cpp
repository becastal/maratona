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
	vector<ll> a(n), b(m);
	for (ll& vi : a) cin >> vi;
	for (ll& vi : b) cin >> vi;

	ll l = 0, res = -LINF;
	for (int r = 0; r < n; r++)
	{
		while (l < m and abs(a[r] - b[l]) >= abs(a[r] - b[l + 1]))
			l++;

		res = max(res, abs(a[r] - b[l]));
	}

	cout << res << endl;
    
    return(0);
}
