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

const int MAX = 1e6 + 10;

struct nodo {
	int maior, abre, fecha;
};

namespace seg {
	nodo seg[4*MAX];
	string s;
	int n;

	nodo combina(nodo a, nodo b) {
		nodo res;
		int tmp = min(a.abre, b.fecha);
		res.maior = a.maior + b.maior + tmp;	
		res.abre = a.abre + b.abre - tmp;
		res.fecha = a.fecha + b.fecha - tmp;
		return res;
	}
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r)
		{
			nodo i;
			i.maior = 0;
			if (s[l] == '(') 
				i.abre = 1, i.fecha = 0;
			else
				i.abre = 0, i.fecha = 1;
			return seg[p] = i;
		}
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return nodo();
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
};

int main()
{
    _;

	string s; cin >> s;
	seg::s = s;
	seg::n = s.size();

	seg::build();

	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r; l--, r--;
		cout << 2 * seg::query(l, r).maior << endl;
	}
    
    return(0);
}
