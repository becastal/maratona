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

	int ok = 1;
	for (int i = 0; i < n and ok; i += 2) {
		ok &= (v[0]&1) == (v[i]&1);
	}
	for (int i = 1; i < n and ok; i += 2) {
		ok &= (v[1]&1) == (v[i]&1);
	}

	cout << (ok ? "YES" : "NO") << endl;
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
