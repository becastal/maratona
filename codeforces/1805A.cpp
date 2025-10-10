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

	vector<int> v(n);
	for (int& i : v) cin >> i;

	for (int x = 0; x < (1 << 8); x++) {

		int agr = 0;
		for (int i : v) {
			agr ^= (i ^ x);
		}
		if (!agr) return cout << x << endl, 0;
	}
	cout << -1 << endl;
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
