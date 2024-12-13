/*
aritmetica modular

descricao:
	da pra usar mint como se fosse int normal

complexidades:
	tudo o(1) menos '/' e pow que eh alguma coisa
	esquisita
*/
struct modInt {
  	unsigned x;
  	static int mod;

	modInt() : x(0) { }
	modInt(signed sig) : x((sig % mod + mod) % mod) { }
	modInt(signed long long sig) : x((sig % mod + mod) % mod) { }
	
	int get() const { return (int)x; }

	modInt pow(long long p) const {
		modInt res = 1, a = *this;
		while (p) {
			if (p & 1) res *= a;
			a *= a; 
			p >>= 1;
		}
		return res;
	}
	modInt& operator+=(modInt that) { if ((x += that.x) >= mod) x -= mod; return *this; }
	modInt& operator-=(modInt that) { if ((x += mod - that.x) >= mod) x -= mod; return *this; }
	modInt& operator*=(modInt that) { x = (__int128)x * that.x % mod; return *this; }
	modInt& operator/=(modInt that) { return (*this) *= that.pow(mod - 2); }
	modInt operator+(modInt that) const { return modInt(*this) += that; }
	modInt operator-(modInt that) const { return modInt(*this) -= that; }
	modInt operator*(modInt that) const { return modInt(*this) *= that; }
	modInt operator/(modInt that) const { return modInt(*this) /= that; }
	bool operator<(modInt that) const { return x < that.x; }
	bool operator>(modInt that) const { return x > that.x; }
	friend ostream& operator<<(ostream& os, modInt a) { os << a.x; return os; }
	friend istream& operator>>(istream& is, modInt& a) { is >> a.x; a.x = (a.x % mod + mod) % mod; return is; 
	}
};
