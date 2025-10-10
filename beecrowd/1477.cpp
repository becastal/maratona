#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 1e5+10;
namespace seg {
	struct nodo {
		int C[3];
		nodo() { memset(C, 0, sizeof(C)); };
		nodo(int a) { memset(C, 0, sizeof(C)), C[a] = 1; };
		nodo friend operator+(nodo a, nodo b) {
			nodo c;
			for (int i = 0; i < 3; i++) {
				c.C[i] = a.C[i] + b.C[i];
			}
			return c;
		};
	};
	int n, *v, lazy[4*MAX];
	nodo seg[4*MAX];

	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(v[l]);
		int m = (l + r) / 2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build_(int n_, int* v_) {
		n = n_, v = v_;
		memset(lazy, 0, sizeof(lazy));
		build();
	}
	void prop(int p, int l, int r) {
		if (lazy[p] == 0) return;
		for (int i = 0; i < lazy[p]; i++) {
			swap(seg[p].C[0], seg[p].C[1]);
			swap(seg[p].C[0], seg[p].C[2]);
		}

		if (l != r) {
			lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
			lazy[2*p] %= 3, lazy[2*p+1] %= 3;
		}
		lazy[p] = 0;
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or a > r) return nodo();
		if (l >= a and r <= b) return seg[p];
		int m = (l + r) / 2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	nodo update(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or a > r) return seg[p];
		if (l >= a and r <= b) {
			lazy[p]++;
			lazy[p] %= 3;
			prop(p, l, r);
			return seg[p];
		}
		int m = (l + r) / 2;
		return seg[p] = update(a, b, 2*p, l, m) + update(a, b, 2*p+1, m+1, r);
	}
}

int solve(int n, int m) {
	vector<int> A(n, 0);
	
	seg::build_(n, A.data());
	while (m--) {
		char tp; cin >> tp;
		int a, b; cin >> a >> b; a--, b--;
		
		if (tp == 'C') {
			seg::nodo R = seg::query(a, b);
			cout << R.C[0] << ' ' << R.C[1] << ' ' << R.C[2] << endl;
		} else {
			seg::update(a, b);
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1, n, m; //cin >> t;
	while (cin >> n >> m) {
		solve(n, m);
		cout << endl;
	}
    
    return(0);
}

