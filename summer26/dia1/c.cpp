#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 350050;
namespace seg {
	int seg[4*MAX], lazy[4*MAX];
	int n, *v;
	
	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l + r) / 2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n_, int* v_) {
		n = n_, v = v_;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) {
			lazy[2*p] += lazy[p];
			lazy[2*p+1] += lazy[p];
		}
		lazy[p] = 0;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return LLONG_MIN;
		int m = (l + r) / 2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l + r) / 2;
		return seg[p] = max(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};

signed solve() {
	string S; cin >> S;
	int n = S.size(), res = 0;

	vector<int> P(n, 0);
	seg::build(n, P.data());

	stack<int> St;
	for (int i = 0, pref = 0; i < n; i++) {
		pref += (S[i] == '(' ? +1 : -1);
		if (S[i] == '(') {
			St.push(i);
		} else {
			int l = i - St.top(), h; St.pop();

			if (l == 1) {
				h = 1;
				seg::update(i, i, 1);
			} else {
				h = seg::query(i - l, i) + 1;
				seg::update(i, i, h);
			}
			//cout << "(" << l << ", " << h << ")" << endl;

			res += (pref & 1 ? -1 : +1) * (h * l);
		}
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
