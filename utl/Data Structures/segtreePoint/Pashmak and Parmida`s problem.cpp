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
        int m = (l+r)/2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        merge(seg[2*p].begin(), seg[2*p].end(), seg[2*p+1].begin(), seg[2*p+1].end(), back_inserter(seg[p]));
    }
    void build(int n2, vector<int>& v2) {
        n = n2, v = v2;
        seg.resize(4*n);
        build();
    }
    int query(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b)
			return lower_bound(seg[p].begin(), seg[p].end(), x) - seg[p].begin();
        int m = (l+r)/2;
        return query(a, b, x, 2*p, l, m) + query(a, b, x, 2*p+1, m+1, r);
    }
};

int main() {
	_;
    int n, q;
    cin >> n;
    vector<int> v(n), prea(n), preb(n);
	for (int& vi : v)
		cin >> vi;

	map<int, int> mp;
	for (int i = 0; i < n; i++)
		prea[i] = ++mp[v[i]];

	mp.clear();
	for (int i = n - 1; i >= 0; i--)
		preb[i] = ++mp[v[i]];

    seg::build(n, preb);
	ll res = 0;
	for (int i = 0; i < n; i++)
		res += seg::query(i + 1, n - 1, prea[i]);

	cout << res << endl;

	// uma prefixsum de cada lado contando o f() de cada pos. dai eu faco contar quantos valores prea[i] > preb[j]
	// pra j = i + 1 ate n - 1, mas faco isso com uma query de segtree merge sort.
	// dai a solucao eh o(nlog^2n)


    return 0;
}
 