#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAXA = 1e6+10;
ll D[MAXA];
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) D[i] = 1;

	for (int i = 2; i <= lim; i++)
		for (int j = i; j <= lim; j += i) {
			D[j]++;
		}
}

const int MAXN = 3e5+10;
namespace seg {
	struct nodo {
		ll soma; int mx;
		nodo() : soma(0), mx(0) {};
		nodo(int x) : soma(x), mx(x) {};
		nodo(ll x, int y) : soma(x), mx(y) {};
	};
	nodo seg[4*MAXN];	
	int n, *v;

	nodo combina(nodo a, nodo b) {
		return nodo(a.soma + b.soma, max(a.mx, b.mx));
	};
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(v[l]);
		int m = (l + r) / 2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	};
	void build(int n_, int* v_) {
		n = n_, v = v_;
		build();
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (r < a or b < l) return nodo(0);
		int m = (l + r) / 2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	nodo update(int a, int b, int p=1, int l=0, int r=n-1) {
		if (r < a or b < l or seg[p].mx <= 2) return seg[p];
		if (l == r) return seg[p] = nodo(D[seg[p].mx]);
		int m = (l + r) / 2;
		return seg[p] = combina(update(a, b, 2*p, l, m), update(a, b, 2*p+1, m+1, r));
	}
}

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	seg::build(n, A.data());
	while (m--) {
		int tp, l, r; cin >> tp >> l >> r; l--, r--;

		if (tp == 1) seg::update(l, r);
		else cout << seg::query(l, r).soma << endl;
		//for (int i = 0; i < n; i++) cout << seg::query(i, i).mx << " \n"[i == n-1]; 
	}

	return(0);
}

int main()
{
    _;

	crivo(MAXA-1);
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
