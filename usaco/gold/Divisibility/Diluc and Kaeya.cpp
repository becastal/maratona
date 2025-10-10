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
	int n, d = 0, k = 0; cin >> n;
	string s; cin >> s;
	
	map<pair<int, int>, int> f;
	for (int i = 0; i < n; i++) {
		d += (s[i] == 'D');
		k += (s[i] == 'K');
		
		pair<int, int> p(d / gcd(d, k), k / gcd(d, k));
		cout << ++f[p] << " \n"[i==n-1];
	}

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
