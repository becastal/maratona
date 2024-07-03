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
typedef vector<int> vi;

const int MAX = 1e5+10;

namespace seg {
	vector<vi> seg(4*MAX, vi(9, 0));
	vi lazy(4*MAX, 0);
	int n;

	vi combina(vi a, vi b)
	{
		vi r(9, 0);
		for (int i = 0; i < 9; i++)
			r[i] = a[i] + b[i];
		return r;
	}

	vi build(int p=1, int l=0, int r=n-1) {
		if (l == r)
		{
			seg[p][1] = 1;
			return seg[p];
		}
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}

	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		vi adi(9, 0);
		for (int i = 0; i < 9; i++)
			adi[(i + lazy[p]) % 9] = seg[p][i];
		seg[p] = adi;

		if (l != r) lazy[2 * p] += lazy[p], lazy[2 * p + 1] += lazy[p];
		lazy[p] = 0;
	}

	vi query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return vi(9, 0);
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}

	vi update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}	
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = combina(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
}

int main()
{
    _;

	int n, q; cin >> seg::n >> q;
	seg::build();

	while (q--)
	{
		int l, r; cin >> l >> r;
		vi freq = seg::query(l, r);
		
		int maior_f = 0, maior_v;
		for (int i = 8; i >= 0; i--)
			if (freq[i] > maior_f)
			{
				maior_f = freq[i];
				maior_v = i;
			}

		seg::update(l, r, maior_v);
	}

	for (int i = 0; i < seg::n; i++)
	{
		vi qr = seg::query(i, i);
		for (int j = 0; j < 9; j++)
			if (qr[j])
			{
				cout << j << endl;
				break;
			}
	}
    
    return(0);
}

