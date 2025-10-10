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
	ll tot = 0;
	vector<int> v(n);
	for (int& i : v) cin >> i, tot += i;

	tot %= 3;
	if (tot % 3 == 0) return cout << 0 << endl, 0;
	if (tot == 1) {
		int deu = 0;
		for (int i = 0; i < n and !deu; i++) {
			deu |= v[i] % 3 == 1;	
		}
		
		if (deu) return cout << 1 << endl, 0;
		return cout << 2 << endl, 0;
	}

	return cout << 1 << endl, 0;
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
