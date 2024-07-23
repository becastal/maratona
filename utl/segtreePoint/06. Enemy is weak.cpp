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
        int m = (l + r) / 2;
        build(2 * p, l, m);
        build(2 * p + 1, m + 1, r);
        merge(seg[2 * p].begin(), seg[2 * p].end(), seg[2 * p + 1].begin(), seg[2 * p + 1].end(), back_inserter(seg[p]));
    }
    void init(int n2, vector<int>& v2) {
        n = n2;
        v = v2;
        seg.resize(4 * n);
        build();
    }
    ll query(int a, int b, int x, bool greater, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b)
		{
            if (greater)
                return seg[p].end() - upper_bound(seg[p].begin(), seg[p].end(), x);
            else
                return lower_bound(seg[p].begin(), seg[p].end(), x) - seg[p].begin();
        }
        int m = (l + r) / 2;
        return query(a, b, x, greater, 2 * p, l, m) + query(a, b, x, greater, 2 * p + 1, m + 1, r);
    }
};

int main() {
    _;
    
    int n; 
    cin >> n;
    vector<int> v(n);

    for (int &vi : v)
		cin >> vi;
    
    seg::init(n, v);

	ll res = 0;
    for (int i = 1; i < n - 1; i++)
	{
        ll antes = seg::query(0, i - 1, v[i], true);
        ll depois = seg::query(i + 1, n - 1, v[i], false);
		res += antes * depois;
    }
	cout << res << endl;
    
    return 0;
}

