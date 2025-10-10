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
	int n, tot = 0; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i, tot += i;

	int ok = 0;
	for (int i = 0; i < n and !ok; i++) {
		ok |= (tot - v[i]) % (n - 1) == 0 and (tot - v[i]) / (n - 1) == v[i];
	}

	cout << (ok ? "YES": "NO") << endl;
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
