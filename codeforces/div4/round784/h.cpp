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
	vector<int> cont(31, 0);

	for (int& i : v) {
		cin >> i;
		for (int j = 0; j < 31; j++) {
			cont[j] += !!(i & (1 << j));
		}
	}
	
	ll res = 0;
	for (int i = 30; i >= 0; i--) {
		int falta = n - cont[i];

		if (falta <= k) {
			k -= falta;
			res += (1LL << i);
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
