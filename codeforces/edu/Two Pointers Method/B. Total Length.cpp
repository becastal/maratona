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
	int n; cin >> n;
	ll p, res = 0; cin >> p;

	vector<int> A(n);
	for (int& i : A) cin >> i;

	for (ll r = 0, l = 0, s = 0; r < n; r++) {
		s += A[r];

		while (s > p) {
			s -= A[l++];
		}

		res += (r - l + 1) * ((r - l + 1) + 1) / 2;
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
