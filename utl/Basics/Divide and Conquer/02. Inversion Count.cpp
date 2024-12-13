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

	function<ll(int, int, int)> merge = [&] (int l, int m, int r) {
		ll res = 0;
		int i = l, j = m + 1;

		vector<int> temp;
		while (i <= m and j <= r) {
			if (v[i] <= v[j]) {
				temp.push_back(v[i++]);
			} else {
				temp.push_back(v[j++]);
				res += (m - i + 1);
			}
		}

		while (i <= m) temp.push_back(v[i++]);
		while (j <= r) temp.push_back(v[j++]);

		for (int k = l; k <= r; k++) {
			v[k] = temp[k-l];	
		}

		return res;
	};

	function<ll(int, int)> conta = [&] (int l, int r) {
		ll res = 0;
		if (l < r) {
			int m  = (r + l) / 2;
			res += conta(l, m);
			res += conta(m+1, r);
			res += merge(l, m, r);
		}
		return res;
	};
	ll res = conta(0, n-1);

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
