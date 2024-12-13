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
	ll soma = 0;
	vector<int> v(n);
	for (int& i : v) cin >> i, soma += i;
	if (n == 1 or n == 2) return cout << -1 << endl, 0;

	sort(v.begin(), v.end());
	int x = v[n/2];
	//2 * n * x - soma + 1
	cout << max(0LL, 2 * (ll)n * (ll)x - soma + 1) << endl;
	
	return 0;
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
