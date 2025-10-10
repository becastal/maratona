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
    vector<vector<int>> seg;
	vector<int> v;
    int n;

    void build(int p=1, int l=0, int r=n-1) {
        if (l == r)
		{
            seg[p].push_back(v[l]);
            return;
        }
        int m = (l+r)/2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        merge(seg[2*p].begin(), seg[2*p].end(), seg[2*p+1].begin(), seg[2*p+1].end(), back_inserter(seg[p]));
    }
    void build(int n2, vector<int>& v2) {
        n = n2, v = v2;
        seg.resize(4*n, {});
        build();
    }
    int query(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return int(lower_bound(seg[p].begin(), seg[p].end(), x) - seg[p].begin());
        int m = (l+r)/2;
        return query(a, b, x, 2*p, l, m) + query(a, b, x, 2*p+1, m+1, r);
    }
};

int solve() {
	int n, q; cin >> n >> q;

	vector<int> p(n), pos(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
		pos[p[i]] = i;
	}
	seg::build(n, p);

	while (q--) {
		int l, r, x; cin >> l >> r >> x; l--, r--, x--;

		if (pos[x] < l or pos[x] > r) {
			cout << -1 << ' ';
			continue;
		}

		int res = 0, ok = 1;
		while (ok) {
			int m = (l + r) / 2;

			if (p[m] == x) break;
			
			if (pos[x] < m) {
				if (p[m] > x) {
					res++;
					if (!menor--) ok = 0;
				}
				r = m - 1;
			} else if (pos[x] > m) {
				if (p[m] < x) {
					res++;
					if (!maior--) ok = 0;
				}
				l = m + 1;	
			}
			ok &= l < r;
		}

		cout << (ok ? (res ? res+1 : 0) : -1) << ' ';
	}
	cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
