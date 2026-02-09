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

const int MAX = 5e5+10;
namespace seg {
	int seg[4*MAX], v[MAX];
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = -INF;
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return -INF;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = max(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
	}
};

int solve() {
	int n, D, R; cin >> n >> D >> R;
	vector<int> h(n), pos(n);
	seg::n = n; seg::build();

	for (int i = 0; i < n; i++) {
		cin >> h[i], h[i]--; 
		pos[h[i]] = i;
	}

	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		if (i - D >= 0) {
			seg::update(pos[i-D], dp[i-D]);
		}

		int l = max(0, pos[i] - R), r = min(n-1, pos[i] + R);
		int agr = seg::query(l, r);

		dp[i] = (agr < 0 ? 0 : agr + 1);
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;

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
