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
	vector<int> a(n), b(m);
	int mx = 0;

	for (int& i : a) cin >> i, mx = max(mx, i);
	for (int& i : b) cin >> i, mx = max(mx, i);

	int res = mx;
	for (int ii = mx; ii >= 0; ii--) {

		int ok = 1;
		for (int i = 0; i < n and ok; i++) {
			int oki = 0;
			for (int j = 0; j < m; j++) {
				oki |= (a[i] & b[j]) | ii == ii;
			}
			ok &= oki;
		}

		if (ok) res = min(res, ii);
	}
	
	cout << res << endl;
    
    return(0);
}
