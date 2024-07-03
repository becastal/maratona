#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
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

using namespace chrono;
struct timer : high_resolution_clock {
	const time_point start;
	timer(): start(now()) {}
	int operator()() {
		return duration_cast<milliseconds>(now() - start).count();
	}
};

namespace seg {
	vi seg[4 * MAX];
	int lazy[4 * MAX], cont[9];
	int n;

	void build(int p=1, int l=0, int r=n-1) {
		seg[p] = vi(9, 0);
		if (l == r)
		{
			seg[p][1] = 1;
			return;
		}
		int m = (l+r)>>1;
		build(2*p, l, m), build(2*p+1, m+1, r);
		seg[p][1] = r - l + 1;
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

	void query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b)
		{
			for (int i = 0; i < 9; i++)
				cont[i] += seg[p][i];
			return;
		}
		if (b < l or r < a) return;
		int m = (l+r)>>1;
		if (m >= a) query(a, b, 2*p, l, m);
		if (m + 1 <= a) query(a, b, 2*p + 1, m+1, r);
	}

	void update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a) return;
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return;
		}	

		int m = (l+r)>>1;
		update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r);
		for (int i = 0; i < 9; i++)
			seg[p][i] = seg[2 * p][i] + seg[2 * p + 1][i];
	}
}


int main()
{
    _;
	timer T;
	int q; scanf("%d%d", &seg::n, &q);
	seg::build();

	while (q--)
	{
		int l, r; scanf("%d%d", &l, &r);
		memset(seg::cont, 0, sizeof seg::cont);
		seg::query(l, r);
		
		int val = 0;
		for (int i = 1; i < 9; i++)
			if (seg::cont[i] >= seg::cont[val]) val = i;

		seg::update(l, r, val);
	}

	for (int i = 0; i < seg::n; i++)
	{
		memset(seg::cont, 0, sizeof seg::cont);
		seg::query(i, i);
		for (int j = 0; j < 9; j++)
			if (seg::cont[j])
			{
				printf("%d\n", j);
				break;
			}
	}
	printf("em %dms\n", T());
    
    return(0);
}

