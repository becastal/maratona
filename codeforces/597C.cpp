#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e5+10;
namespace seg {
	ll seg[4*MAX][12], lazy[4*MAX][12];
	int n;

	ll build(int k, int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p][k] = 0;
		int m = (l+r)/2;
		return seg[p][k] = build(k, 2*p, l, m) + build(k, 2*p+1, m+1, r);
	}
	ll query(int k, int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p][k];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(k, a, b, 2*p, l, m) + query(k, a, b, 2*p+1, m+1, r);
	}
	ll update(int k, int a, int b, ll x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) {
			seg[p][k] += x;
			return seg[p][k];
		}
		if (b < l or r < a) return seg[p][k];
		int m = (l+r)/2;
		return seg[p][k] = update(k, a, b, x, 2*p, l, m) + update(k, a, b, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, k; cin >> n >> k; k++;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	seg::n = *max_element(all(A)) + 1;
	for (int i = 1; i <= k; i++) seg::build(i);

	for (int i = 0; i < n; i++) {
		for (int j = 2; j <= k; j++) {
			seg::update(j, A[i], A[i], seg::query(j-1, 0, A[i]-1));
		}
		seg::update(1, A[i], A[i], +1);
	}

	cout << seg::query(k, 0, *max_element(all(A))) << endl;

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
