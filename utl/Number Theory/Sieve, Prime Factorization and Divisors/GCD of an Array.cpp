#include <bits/stdc++.h>
//#define f first
//#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 2e5+10;
const int mod = 1e9+7;

int divi[MAX];
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(map<int, int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v[divi[n]]++;
}

map<int, int> primos(int x) {
	map<int, int> res;	
	fact(res, x);
	return res;
}

ll pow(ll x, ll y, ll m) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

namespace seg {
    struct nodo {
        map<int, int> f;
        nodo() {}
        nodo (int x) {
            f = primos(x);
        }
        int val () {
            ll res = 1;
            for (auto [i, j] : f) {
                if (j) res = (res * pow(i, j, mod)) % mod;
            }
            return (int)res;
        }
        friend nodo operator +(nodo a, nodo b) {
            nodo c;
            for (auto [i, j] : a.f) {
				if (b.f.count(i)) c.f[i] = min(j, b.f.at(i));
            }
            return c;
        }
        friend nodo operator *(nodo a, int b) {
			for (auto [i, j] : primos(b)) {
				a.f[i] += j;
			}
			return a;
        }
    };
	nodo seg[4*MAX];
	int n, v[MAX];

	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(v[l]);
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	nodo update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = seg[p] * x;
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
	}
};

int main()
{
    _;

	crivo(MAX-1);
	int n, q; cin >> n >> q; seg::n = n;
	for (int i = 0; i < n; i++) {
		cin >> seg::v[i];
	}
	seg::build();	
	
	for (int i = 0, ii, x; i < q; i++) {
		cin >> ii >> x; ii--;
		cout << seg::update(ii, x).val() << endl;
	}
    
    return(0);
}
