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

const int MAX = 2e5+10;
const int mod = 1000007;
namespace seg {
	int seg[4*MAX], v[MAX];
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = (build(2*p, l, m) + build(2*p+1, m+1, r)) % mod;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return (query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r)) % mod;
	}
	int update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = (update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r)) % mod;
	}
};

void solve() {
	int k, n; cin >> k >> n; seg::n = n;
	for (int i = 0; i < n; i++) {
		seg::v[i] = 0;
	}
	for (int i = 0; i < k and i < n; i++) {
        seg::v[i] = i; 
    }
	seg::build();

	for (int i = k; i < n; i++) {
		seg::update(i, seg::query(i - k, i - 1));
	}
	
	cout << seg::query(n-1, n-1) << endl;
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
