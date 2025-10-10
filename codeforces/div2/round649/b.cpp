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
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<int> res(n, 1);
	for (int l = 0, r; l < n-1;) {
		r = l+1;
		int tp = v[l] < v[r];

		while (r < n and v[r-1] < v[r] == tp) {
			res[r++] = 0;
		}

		res[--r] = 1;
		l = r;
	}

	cout << accumulate(res.begin(), res.end(), 0) << endl;
	for (int i = 0; i < n; i++) {
		if (res[i]) cout << v[i] << ' ';
	}
	cout << endl;
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
