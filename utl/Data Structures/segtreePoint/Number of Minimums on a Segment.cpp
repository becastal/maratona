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

const int MAX = 1e5+10;
int v[MAX];
ii seg[4*MAX]; // min, freq do min;

ii combina(ii a, ii b)
{
	if (a.f < b.f) return a;
	if (b.f < a.f) return b;
	return {a.f, a.s + b.s};
}

ii build(int p, int l, int r)
{
	if (l == r) return seg[p] = {v[l], 1};
	int m = (l + r) / 2;
	return seg[p] = combina(build(2*p, l, m), build(2*p + 1, m + 1, r));
}

ii query(int a, int b, int p, int l, int r)
{
	if (b < l or r < a) return {INF, -1};
	if (a <= l and r <= b) return seg[p];
	int m = (l + r) / 2;
	return combina(query(a, b, 2*p, l, m), query(a, b, 2*p + 1, m + 1, r));
}

ii update(int i, int x, int p, int l, int r)
{
	if (i < l or r < i) return seg[p];
	if (l == r) return seg[p] = {x, 1};
	int m = (l + r) / 2;
	return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p + 1, m + 1, r));
}

int main()
{
    _;

	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	build(1, 0, n - 1);

	while (q--)
	{
		char t; cin >> t;
		if (t == '1')
		{
			int i, x; cin >> i >> x;
			update(i, x, 1, 0, n - 1);
		}
		else
		{
			int l, r; cin >> l >> r; r--;
			ii res = query(l, r, 1, 0, n - 1);
			cout << res.f << ' ' << res.s << endl;
		}
	}
	
    
    return(0);
}
