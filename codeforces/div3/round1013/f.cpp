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
    mod_int(ll v_) {
        if (v_ >= p or v_ <= -p) v_ %= p;
        if (v_ < 0) v_ += p;
        v = v_;
    }
    m& operator +=(const m& a) {
        v += a.v;
        if (v >= p) v -= p;
        return *this;
    }
    m& operator -=(const m& a) {
        v -= a.v;
        if (v < 0) v += p;
        return *this;
    }
    m& operator *=(const m& a) {
        v = v * ll(a.v) % p;
        return *this;
    }
    m& operator /=(const m& a) {
        v = v * inv(a.v) % p;
        return *this;
    }
    m operator -(){ return m(-v); }
    m& operator ^=(ll e) {
        if (e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e);
        return *this;
    }
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
typedef mod_int<998244353> mint;

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<string> M(n);
    for (auto& i : M) cin >> i;
    
    auto ok = [&](int i, int j, int ii, int jj) {
        return ((i-ii)*(i-ii) + (j-jj)*(j-jj)) <= d*d;
    };
    
    int R1 = 0;
    if(d*d - 1 >= 0) {
        R1 = (int)floor(sqrt((long double)d*d - 1e-9));
    }
    
    vector<vector<mint>> dp(n, vector<mint>(m, 0));
    
	vector<mint> v(m, 0);
    for (int j = 0; j < m; j++) {
        if(M[n-1][j] == 'X') v[j] = 1;
    }
    vector<mint> pre(m+1, 0);
    for (int j = 1; j <= m; j++) {
        pre[j] = pre[j-1] + v[j-1];
    }
    for (int j = 0; j < m; j++) {
        if(M[n-1][j] == 'X'){
            int l = max(0, j - d);
            int r = min(m-1, j + d);
            dp[n-1][j] = pre[r+1] - pre[l];
        }
    } 

    for (int i = n-2; i >= 0; i--) {
        vector<mint> dp_base(m, 0), dp_(m, 0), seg(m+1, 0), seg_(m+1, 0);
        
		for (int j = 1; j <= m; j++) {
			seg[j] = seg[j-1] + dp[i+1][j-1];
		}

        for (int j = 0; j < m; j++) {
            if(M[i][j] == 'X'){
                int l = max(0, j - R1);
                int r = min(m-1, j + R1);
                dp_base[j] = seg[r+1] - seg[l];
            }
        }
        
		for (int j = 1; j <= m; j++) {
			seg_[j] = seg_[j-1] + dp_base[j-1];
		}
        
        for (int k = 0; k < m; k++) {
            if(M[i][k] == 'X'){
                int l = max(0, k - d);
                int r = min(m-1, k + d);
                dp_[k] = seg_[r+1] - seg_[l];
            }
        }
        dp[i] = dp_;
    }
    
    mint res = 0;
    for (int j = 0; j < m; j++) {
        res += dp[0][j];
    }
    cout << res << endl;
}
  
int main()
{
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return(0);
}
