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

void solve_() {
	int n, k; cin >> n >> k;
	vector<int> v(n), res(n, INF);
	iota(v.begin(), v.end(), 1);

	do {
		vector<int> pre(n+1, 0);
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i-1] + v[i-1];
		}

		int mx = -INF, mn = INF;
		for (int i = 0; i <= n-k; i++) {
			mx = max(mx, pre[i+k] - pre[i]);	
			mn = min(mn, pre[i+k] - pre[i]);	
		}
		
		if (mx - mn <= 1) res = min(res, v);
	} while (next_permutation(v.begin(), v.end()));

	for (int i : res) cout << i << ' '; cout << endl;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> res(n);

	vector<int> pos = {1, n};
	for (int i = 0; i < k; i++) {
		for (int j = i; j < n; j += k) {
			res[j] = pos[j&1];
			pos[j&1] += (j & 1 ? -1 : +1);
		}
	}
	for (int i : res) cout << i << ' '; cout << endl;
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
