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
namespace seg {
	int seg[4*MAX];
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	int update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q; cin >> n >> q; seg::n = n;
	vector<int> h(n), A(n);
	for (int& i : h) cin >> i;

	vector<vector<int>> L(n+1);
	stack<int> s;
	for (int i = 0; i < n; i++) {
		while (s.size() and h[s.top()] < h[i]) {
			s.pop();
		}

		A[i] = (s.empty() ? 0 : s.top() + 1);
		L[A[i]].push_back(i);

		s.emplace(i);
	}

	vector<tuple<int, int, int>> Q(q);
	vector<int> res(q);
	int cont = 0;
	for (auto& [l, r, id] : Q) cin >> l >> r, l--, r--, id = cont++;

	seg::build();
	sort(Q.begin(), Q.end());
	for (int i = 0, j = 0; i < q; i++) {
		auto [l, r, id] = Q[i];

		while (j <= l) {
			for (int ii : L[j]) {
				seg::update(ii, 1);
			}
			j++;
		}

		res[id] = seg::query(l, r);
	}
	for (int i : res) cout << i << endl;

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
