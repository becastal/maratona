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
typedef pair<int, int> ii;
typedef pair<ii, ii> pi;

namespace seg {
	vector<pi> seg;
	vector<int> v;
	int n;

	pi combina(pi a, pi b) {
		vector<ii> V = {{a.f.f, a.f.s}, {a.s.f, a.s.s}, {b.f.f, a.f.s}, {b.s.f, a.s.s}};
		sort(V.rbegin(), V.rend());

		for (auto it = V.begin() + 1; it != V.end();)
		{
			if (it->first == -1)
				it = V.erase(it);
			else if (it->first == prev(it)->first)
			{
				prev(it)->second += it->second;
				it = V.erase(it);
			}
			else
				++it;
		}
		int v1 = 0, c1 = 0, v2 = 0, c2 = 0;
		if (V.size() > 0)
			v1 = V[0].f, c1 = V[0].s;
		if (V.size() > 1)
			v2 = V[1].f, c2 = V[1].s;
		
		return {{v1, c1}, {v2, c2}};
    }
	pi build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {{v[l], 1}, {v[l], 1}};
		int m = (l + r) / 2;
		return seg[p] = combina(build(2*p, l, m), build(2*p + 1, m + 1, r));
	}
	void builda() {
		seg.resize(4*n);
		build();
	}
	pi query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return {{-1, -1}, {-1, -1}};
		if (a <= l and r <= b) return seg[p];
		int m = (l + r) / 2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p + 1, m + 1, r));
	}
	pi update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = {{x, 1}, {x, 1}};
		int m = (l + r) / 2;
		return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p + 1, m + 1, r));
	}
};

int main()
{
    _;

	int n, q; cin >> n >> q;
	seg::n = n;
	seg::v.resize(n);
	for (int& vi : seg::v)
		cin >> vi;

	seg::builda();

	while (q--)
	{
		char t; cin >> t;
		if (t == '1')
		{
			int i, x; cin >> i >> x;
			seg::update(i, x);
		}
		else
		{
			int l, r; cin >> l >> r; l--, r--;
			cout << seg::query(l, r).s.s << endl;
		}
	}
	
    
    return(0);
}
