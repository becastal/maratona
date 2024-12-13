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
typedef pair<int, int> ii;
#define sq(x) ((x)*(x))

void solve() {
	int x, y, k;
	cin >> x >> y >> k;

	auto dist = [] (ii a, ii b) {
		return sqrt(sq(a.f - b.f) + sq(a.s - b.s));
	};

	for (int i = 0; i <= x; i++) {
		if (dist(ii(0, 0), ii(i, y)) >= k) {
			if (i % y) continue;

			cout << 0 << ' ' << 0 << ' ' << i << ' ' << y << endl;
			cout << x << ' ' << 0 << ' ' << 0 << ' ' << x * i / y << endl;
			return;
		}
	}
	cout << endl;
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
