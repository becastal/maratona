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
	ll seg[4*MAX];
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q, cnt = 0; cin >> n >> q; seg::n = n;
	vector<int> v(n), e;
	for (int& i : v) cin >> i, e.push_back(i);

	vector<array<int, 5>> A(q);
	for (auto& [a, b, l, r, id] : A) {
		cin >> l >> r >> a >> b; l--, r--, a--;
		id = cnt++;
		e.push_back(a), e.push_back(b);
	}

	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.end());

	int m = e.size();
	vector<vector<int>> ev(m);
	for (int i = 0; i < n; i++) {
		v[i] = lower_bound(e.begin(), e.end(), v[i]) - e.begin();
		ev[v[i]].push_back(i);
	}

	for (auto& [a, b, l, r, id] : A) {
		a = lower_bound(e.begin(), e.end(), a) - e.begin();
		b = lower_bound(e.begin(), e.end(), b) - e.begin();
	}

	vector<int> res(q);
	for (int k = 0; k <= 1; k++) {
		seg::build();

		sort(A.begin(), A.end(), [&](array<int, 5> i, array<int, 5> j) {
			return i[k] < j[k];
		});

		int j = 0;
		for (auto ar : A) {
			auto [a, b, l, r, id] = ar;

			while (j <= ar[k]) {
				for (int jj : ev[j]) {
					seg::update(jj, k ? +1 : -1);
				}
				j++;
			}

			res[id] += seg::query(l, r);
		}
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
