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

	vector<int> A(n);
	for (int& i : A) cin >> i;

	ll res = 0;
	map<int, int> f;
	for (int r = 0, l = 0; r < n; r++) {
		f[A[r]]++;
		while ((int)f.size() < (r - l + 1)) {
			if (--f[A[l]] == 0) f.erase(A[l]);
			l++;
		}

		//cout << l << ' ' << r << endl;
		res += (r - l + 1);
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
