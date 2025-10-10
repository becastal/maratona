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
	int n, x, s = 0; cin >> n >> x;
	vector<int> a(n), f(3, 0);
	for (int& i : a) {
		cin >> i;
		s ^= (i % 3);
		f[i % 3]++;
	}

	int ok = 0;
	if (x) {
		if (s == 0) {
			ok = f[0] or x % 2 == 0;
		} else {
			ok = f[1] % 2 == 1 and f[2] % 2 == 1 and (f[0] or x % 2 == 1);
		}
	} else {
		ok = s == 0;
	}
	cout << (ok ? "Giovana" : "Julia") << endl;


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
