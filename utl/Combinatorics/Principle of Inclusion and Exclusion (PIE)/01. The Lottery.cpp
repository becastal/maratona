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

int main()
{
    _;

    int n, m; 
    while (cin >> n >> m) {
        vector<int> vruim(m), v;
        for (int& i : vruim) cin >> i;

        for (int i = 0; i < m; i++) {
            int ok = 1;
            for (int j = 0; j < m and ok; j++) {
                if (i != j) {
                    ok &= vruim[i] % vruim[j] != 0;
                }
            }
            if (ok) v.push_back(vruim[i]);
        }

        int ruim = 0;
        for (int i = 1; i < (1 << v.size()); i++) {
            int agr = 1, ok = 1;
            for (int j = 0; j < v.size() and ok; j++) {
                if (i & (1 << j)) {
                    if (agr > n / v[j]) {
                        ok = 0;
                    } else {
                        agr *= v[j];
                    }
                }
            }

            ruim += ok * (__builtin_popcount(i) & 1 ? 1 : -1) * (n / agr);
        }

        cout << n - ruim << endl;
    }
    
    return 0;
}

