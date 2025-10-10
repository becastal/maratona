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
	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	int res = 0;
	for (int i = 0, a = 0, b = 0; i < n; i++) {
		if (!a and !b) {
			if (!v[i]) continue;
			res++;
			if (v[i] <= 2) a = 1;
		} else if (a) {
			a = 0;
			if (v[i] <= 2) continue;
			res++;
			if (v[i] <= 4) b = 1;
		} else if (b) {
			b = 0;
			if (!v[i]) continue;
			res++;
			if (v[i] <= 4) a =1;
		}
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
