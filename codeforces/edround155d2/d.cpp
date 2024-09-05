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

template<int mod>
struct modInt {
  	unsigned x;
  	modInt() : x(0) { }
	modInt(signed sig) : x((sig%mod + mod)%mod) {  }
	modInt(signed long long sig) : x((sig%mod + mod)%mod) { }
	int get() const { return (int)x; }
	modInt pow(ll p) { 
		modInt res = 1, a = *this; 
		while (p) { 
			if (p & 1) res *= a; 
			a *= a; p >>= 1; 
		} 
		return res; 
	}
	 
 	modInt &operator+=(modInt that) { if ((x += that.x) >= mod) x -= mod; return *this; }
	modInt &operator-=(modInt that) { if ((x += mod - that.x) >= mod) x -= mod; return *this; }
	modInt &operator*=(modInt that) { x = (__int128)x * that.x % mod; return *this; }
	modInt &operator/=(modInt that) { return (*this) *= that.pow(mod - 2); }
	 
	modInt operator+(modInt that) const { return modInt(*this) += that; }
	modInt operator-(modInt that) const { return modInt(*this) -= that; }
	modInt operator*(modInt that) const { return modInt(*this) *= that; }
	modInt operator/(modInt that) const { return modInt(*this) /= that; }
	bool operator<(modInt that) const { return x < that.x; }
	bool operator>(modInt that) const { return x > that.x; }
	friend ostream& operator<<(ostream &os, modInt a) { os << a.x; return os; }
	friend istream& operator>>(istream &is, modInt &a) { is >> a.x; return is; }
};
typedef modInt<998244353> mint;

int main()
{
    _;
	// a ideia eh resolver o problema pra cada bit. dai o xor de um segmento so vai ser um se a quantidade
	// daquele bit ligados no segmento for impar.
	// fica bem parecido com aquele

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	mint res = 0;
	for (int b = 0; b < 30; b++) {
		int paridade = 0;

		mint agr = 0;
		vector<mint> cont(2), somaL(2);

		cont[0] = 1;
		for (int i = 0; i < n; i++) {
			paridade ^= ((v[i] >> b) & 1);
			mint somaR = cont[paridade^1] * (i+1);
			agr += somaR;
			agr -= somaL[paridade^1];
			
			cont[paridade] += 1;
			somaL[paridade] += (i+1);
		}

		agr *= (1 << b);
		res += agr;
	}

	cout << res << endl;
    
    return(0);
}
