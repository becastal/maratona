#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, d; cin >> n >> d;

	int r = (1 + n) * n / 2 - n, l = 0;
	int nn = n, c = 0;
	while (nn) {
		int tira = min(nn, (1 << c));
		l += tira * c++;
		nn -= tira;
	}

	if (d < l or d > r) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	dbg(l);
	dbg(r);

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
