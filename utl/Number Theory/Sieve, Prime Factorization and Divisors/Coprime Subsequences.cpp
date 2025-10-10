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

template<int p> struct mod_int {
    ll expo(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if (e % 2) ret = ret * b % p;
            e /= 2, b = b * b % p;
        }
        return ret;
    }
    ll inv(ll b) { return expo(b, p-2); }

    using m = mod_int;
    int v;
    mod_int() : v(0) {}
    mod_int(ll v_) { if (v_ >= p or v_ <= -p) v_ %= p; if (v_ < 0) v_ += p; v = v_; }
    m& operator +=(const m& a) { v += a.v; if (v >= p) v -= p; return *this; }
    m& operator -=(const m& a) { v -= a.v; if (v < 0) v += p; return *this; }
    m& operator *=(const m& a) { v = v * ll(a.v) % p; return *this; }
    m& operator /=(const m& a) { v = v * inv(a.v) % p; return *this; }
    m operator -(){ return m(-v); }
    m& operator ^=(ll e) { if (e < 0) { v = inv(v); e = -e; } v = expo(v, e); return *this; }
    bool operator ==(const m& a) { return v == a.v; }
    bool operator !=(const m& a) { return v != a.v; }
    friend istream& operator >>(istream& in, m& a) {
        ll val; in >> val;
        a = m(val);
        return in;
    }
    friend ostream& operator <<(ostream& out, m a) {
        return out << a.v;
    }
    friend m operator +(m a, m b) { return a += b; }
    friend m operator -(m a, m b) { return a -= b; }
    friend m operator *(m a, m b) { return a *= b; }
    friend m operator /(m a, m b) { return a /= b; }
    friend m operator ^(m a, ll e) { return a ^= e; }
};
const int MAX = 100010;
int divi[MAX];
typedef mod_int<(int)1e9+7> mint;

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

vector<int> f_(int x) {
    vector<int> v;
    fact(v, x);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

int main()
{
    _;
    vector<mint> p2(MAX+1, mint(1));
    for (int i = 1; i <= MAX; i++) {
        p2[i] = p2[i-1] * mint(2);
    }
    crivo(MAX-1);
    
    int n; 
    cin >> n;
    
    int uns = 0;
    map<int, int> M;
    mint ruins = 0;
    for (int i = 0; i < n; i++){
        int x; 
        cin >> x;
        if(x == 1) {
            uns++;
            continue;
        }
        
        auto f = f_(x);	
        int m = f.size();
        
        mint agr = 1;
        for (int mask = 1; mask < (1 << m); mask++) {
            int p = 1;
            for (int j = 0; j < m; j++) {
                if(mask & (1 << j)) {
                    p *= f[j];
                }
            }
			agr += (__builtin_popcount(mask) & 1 ? mint(1) : mint(-1)) * (p2[M[p]] - 1);
			M[p]++;
        }
        ruins += agr;
    }
    cout << (p2[n - uns] - 1 - ruins) + (p2[uns] - 1) * p2[n - uns] << endl;
    
    return(0);
}
