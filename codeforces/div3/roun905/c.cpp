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

	if (k == 4) {
		vector<int> cont(2, 0);
		int res = INF;
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			res = min(res, (k - (x % k)) % k);
			cont[x&1]++;
		}

		res = min(res, 2 - min(2, cont[0]));
		cout << res << endl;
		return;
	}

	int res = INF;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		res = min(res, (k - (x % k)) % k);
		//dbg(k - (x % k));
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
