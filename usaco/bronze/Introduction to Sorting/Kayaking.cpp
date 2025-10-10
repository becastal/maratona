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
	int n; cin >> n; n <<= 1;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	int res = INF;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			vector<int> b;
			for (int k = 0; k < n; k++) {
				if (k == i or k == j) continue;
				b.push_back(a[k]);
			}

			sort(b.begin(), b.end());
			int agr = 0;
			for (int k = 1; k < (int)b.size(); k += 2) {
				agr += b[k] - b[k-1];
			}
			res = min(res, agr);
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
