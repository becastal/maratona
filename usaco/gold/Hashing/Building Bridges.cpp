#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

#define sq(x) (1LL * (x)*(x))
const ll LINF = 1e15;

// Li-Chao Tree
//
// Adiciona retas (ax+b), e computa o minimo entre as retas
// em um dado 'x'
// Cuidado com overflow!
// Se tiver overflow, tenta comprimir o 'x' ou usar
// convex hull trick
//
// O(log(MA-MI)), O(n) de memoria

template<ll MI = ll(-1e9), ll MA = ll(1e9)> struct lichao {
	struct line {
		ll a, b;
		array<int, 2> ch;
		line(ll a_ = 0, ll b_ = LINF) :
			a(a_), b(b_), ch({-1, -1}) {}
		ll operator ()(ll x) { return a*x + b; }
	};
	vector<line> ln;

	int ch(int p, int d) {
		if (ln[p].ch[d] == -1) {
			ln[p].ch[d] = ln.size();
			ln.emplace_back();
		}
		return ln[p].ch[d];
	}
	lichao() { ln.emplace_back(); }

	void add(line s, ll l=MI, ll r=MA, int p=0) {
		ll m = (l+r)/2;
		bool L = s(l) < ln[p](l);
		bool M = s(m) < ln[p](m);
		bool R = s(r) < ln[p](r);
		if (M) swap(ln[p], s), swap(ln[p].ch, s.ch);
		if (s.b == LINF) return;
		if (L != M) add(s, l, m-1, ch(p, 0));
		else if (R != M) add(s, m+1, r, ch(p, 1));
	}
	ll query(int x, ll l=MI, ll r=MA, int p=0) {
		ll m = (l+r)/2, ret = ln[p](x);
		if (ret == LINF) return ret;
		if (x < m) return min(ret, query(x, l, m-1, ch(p, 0)));
		return min(ret, query(x, m+1, r, ch(p, 1)));
	}
};

/*

pra um certo j eu tenho que minimizar:

PW[j] - PW[i + 1] 
+
sq(H[i] - H[j])
PW[j] e H[j] sao travados, obviamente.

eu tenho que olhar pra tras e conseguir rapido dizer qual
o par (PW[i + 1], H[i]) maximiza minha resposta.

tem que ser o H[i] mais distante e o menor PW[i+1];
	
eh facil maximizar qualquer um independentemente.
*/

int solve() {
	int n; cin >> n;
	vector<ll> H(n), W(n);

	for (ll& i : H) cin >> i;
	for (ll& i : W) cin >> i;

	vector<ll> PW(n+1, 0);
	for (int i = 1; i <= n; i++) {
		PW[i] = PW[i-1] + W[i-1];
	}

	lichao LC;

	vector<ll> dp(n, LINF);
	dp[0] = 0;

	LC.add({-2 * H[0], dp[0] - PW[1] + sq(H[0])});

	for (int i = 1; i < n; i++) {
		dp[i] = PW[i] + sq(H[i]) + LC.query(H[i]);
		LC.add({-2 * H[i], dp[i] - PW[i+1] + sq(H[i])});
	}
	cout << dp.back() << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

