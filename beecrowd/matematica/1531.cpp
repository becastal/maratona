#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e6+10;

int divi[MAX];
void crivo(int lim) {
    for (int i = 1; i <= lim; i++) 
        divi[i] = 1;
    for (int i = 2; i <= lim; i++) {
        if (divi[i] == 1)
            for (int j = i; j <= lim; j += i)
                divi[j] = i;
    }
}

void fact(vector<int>& v, int n) {
    if (n != divi[n])
        fact(v, n/divi[n]);
    v.push_back(divi[n]);
}

ll mul(ll x, ll y, ll m) {
    return ((x % m) * (y % m)) % m;
}

ll pow(ll x, ll y, ll m) {
    if (!y) return 1;
    ll ans = pow(mul(x, x, m), y/2, m);
    return y % 2 ? mul(x, ans, m) : ans;
}

map<ll, ll> F;
ll f(ll n, ll mod) {
    if (F.count(n)) return F[n];
    ll k = n / 2;
    if (n % 2 == 0) {
        return F[n] = ( f(k, mod)*f(k, mod) + f(k-1, mod)*f(k-1, mod) ) % mod;
    } else {
        return F[n] = ( f(k, mod)*f(k+1, mod) + f(k-1, mod)*f(k, mod) ) % mod;
    }
}

ll gcd_ll(ll a, ll b) {
    while(b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm_ll(ll a, ll b) {
    return (a / gcd_ll(a, b)) * b;
}

int computePisanoPrime(int p) {
    ll leg = pow(5, (p - 1) / 2, p);
    int D;
    if (leg == 1)
        D = p - 1;
    else
        D = 2 * (p + 1);
    
    vector<int> divisors;
    for (int i = 1; i * i <= D; i++) {
        if (D % i == 0) {
            divisors.push_back(i);
            if (i * i != D)
                divisors.push_back(D / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    
    for (int d : divisors) {
        F.clear();
        F[0] = F[1] = 1;
        ll f_d_minus = f(d - 1, p) % p;
        ll f_d = f(d, p) % p;
        if (f_d_minus == 0 && f_d == 1)
            return d;
    }
    return -1;
}

ll pisano(int m) {
    if(m == 1)
        return 1;
    
    vector<int> factors;
    fact(factors, m);
    
    map<int, int> factorCount;
    for (int p : factors)
        factorCount[p]++;
    
    ll result = 1;
    for (auto &entry : factorCount) {
        int p = entry.first, exp = entry.second;
        ll period;
        if (p == 2) {
            if(exp == 1)
                period = 3;
            else if(exp == 2)
                period = 6;
            else
                period = 3LL << (exp - 1); // 3 * 2^(exp-1)
        }
        else if (p == 5) {
            ll power = 1;
            for (int i = 0; i < exp; i++)
                power *= 5;
            period = 4 * power;  // 4 * 5^e
        }
        else {
            int basePisano = computePisanoPrime(p);
            ll power = 1;
            for (int i = 1; i < exp; i++)
                power *= p;
            period = basePisano * power;
        }
        result = lcm_ll(result, period);
    }
    return result;
}

int main() {
    _;
    crivo(MAX - 1);
    
    int n, m;
    while (cin >> n >> m) {
        int p = pisano(m);
        F.clear();
        F[0] = F[1] = 1;
        ll x = f(n-1, p);
        
        F.clear();
        F[0] = F[1] = 1;
        if (!x) cout << 0 << endl;
        else cout << f(x-1, m) << endl;
    }
    return 0;
}

