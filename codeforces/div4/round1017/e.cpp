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
	vector<vector<int>> cont(31, vector<int>(2, 0));
	
	for (int& i : v) {
		cin >> i;

		for (int j = 0; j < 30; j++) {
			cont[j][(i >> j) & 1]++;
		}
	}

	ll res = 0;
	for (int i : v) {
		ll agr = 0;
		for (int j = 0; j < 30; j++) {
			agr += (1LL << j) * cont[j][(i >> j) & 1 ^ 1];		
		}
		res = max(res, agr);
	}
	cout << res << endl;

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
