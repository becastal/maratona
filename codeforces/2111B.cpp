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
	int n, m; cin >> n >> m;

	vector<int> fib(11, 0);
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= n; i++) {
		fib[i] = fib[i-1] + fib[i-2];	
	}

	for (int i = 0, w, l, h; i < m; i++) {
		cin >> w >> l >> h;
		cout << (fib[n] + fib[n-1] <= max({w, l, h}) and fib[n] <= min({w, l, h}) ? '1' : '0');
	}
	cout << endl;

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
