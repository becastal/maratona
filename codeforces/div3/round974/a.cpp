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

	vector<int> v(n);
	for (int& i : v) cin >> i;

	int tenho = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] >= k) { 
			tenho += v[i];
			continue;
		}
		if (!v[i] and tenho) {
			tenho--;
			res++;
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
