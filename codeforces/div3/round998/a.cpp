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
	vector<int> a(5);
	cin >> a[0] >> a[1] >> a[3] >> a[4];

	int res = 0;
	for (int i = -1000; i <= 1000; i++) {
		a[2] = i;
		int agr = 0;
		for (int j = 0; j < 3; j++) {
			agr += (a[j+2] == a[j] + a[j+1]);
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
