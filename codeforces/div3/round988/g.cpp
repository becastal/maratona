#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e6 + 10;
const int mod = 998244353;
int divi[MAX], dp[MAX], p[MAX];

void crivo(int lim) {
    for (int i = 1; i <= lim; i++) divi[i] = i;
    for (int i = 2; i * i <= lim; i++) {
        if (divi[i] == i) {
            for (int j = i * i; j <= lim; j += i) {
                if (divi[j] == j) divi[j] = i;
            }
        }
    }
}

void fact(set<int>& v, int n) {
    while (n > 1) {
        v.emplace(divi[n]);
        n /= divi[n];
    }
}

int main() {
    _;
    
    crivo(MAX - 1);
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int& i : v) cin >> i;

    dp[n-1] = 1;
    for (int i = n-1; i >= 0; i--) {
        set<int> f;
        fact(f, v[i]);

        vector<int> vi(f.begin(), f.end());
        for (int mask = 1; mask < (1 << (int)vi.size()); mask++) {
            int x = 1, bits = __builtin_popcount(mask);
            for (int k = 0; k < vi.size(); k++) {
                if (mask & (1 << k)) x *= vi[k];
            }
            if (bits % 2 == 1) dp[i] = (dp[i] + p[x]) % mod;
            else dp[i] = (dp[i] - p[x] + mod) % mod;
        }

        for (int mask = 1; mask < (1 << (int)vi.size()); mask++) {
            int x = 1;
            for (int k = 0; k < vi.size(); k++) {
                if (mask & (1 << k)) x *= vi[k];
            }
            p[x] = (p[x] + dp[i]) % mod;
        }
    }

	cout << dp[0] << endl;

    return 0;
}

