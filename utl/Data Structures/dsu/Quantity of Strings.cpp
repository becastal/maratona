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

const int mod = 1e9 + 7;

ll powmod(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

struct UF {
    int c;
    vector<int> id, sz;
    UF(int n) : id(n), sz(n, 1) {
        iota(id.begin(), id.end(), 0);
        c = n;
    }

    int find(int i) {
        return (i == id[i] ? i : id[i] = find(id[i]));
    }

    void merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (sz[i] < sz[j]) swap(i, j);
        sz[i] += sz[j], id[j] = i;
        c--;
    }
};

int main()
{
    _;
    int n, m, k;
    cin >> n >> m >> k; k--;
    UF dsu(n);
    for (int l = 0, r; l < n - k; l++) {
        r = l + k;
        for (int ll = l, rr = r; ll <= rr; ll++, rr--) {
            dsu.merge(ll, rr);
        }
    }
    
    cout << powmod(m, dsu.c, mod) << endl;

    return 0;
}

