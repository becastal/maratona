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
	int n; cin >> n;

	vector<int> v(n), res(2, 0);
	for (int& i : v) cin >> i;
	res[0] = v[0];

	int ult = v[0], agr = 1, movs = 1, l = 1, r = n-1;
	while (l <= r) {
		int acum = 0;
		if (!agr) {
			while (l <= r and acum <= ult) {
				acum += v[l++];
			}
		} else {
			while (l <= r and acum <= ult) {
				acum += v[r--];
			}
		}

		res[agr] += acum;
		ult = acum;
		movs++;
		agr ^= 1;
	}

	cout << movs << ' ' << res[0] << ' ' << res[1] << endl;
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
