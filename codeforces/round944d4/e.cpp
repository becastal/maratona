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
    int t; cin >> t;
    while (t--)
    {
        int n, k, q; cin >> n >> k >> q;
        vector<int> a(k), b(k);

        for (auto& ai : a)
            cin >> ai;

        for (auto& bi : b)
            cin >> bi;

        a.insert(a.begin(), 0);
        b.insert(b.begin(), 0);

        for (int i = 0; i < q; i++)
        {
            int qi; cin >> qi;
            if (qi == 0)
            {
                cout << 0 << ' ';
                continue;
            }
            int idx = int(lower_bound(a.begin(), a.end(), qi) - a.begin());
            int a_diff = a[idx] - a[idx - 1];
            int b_diff = b[idx] - b[idx - 1];
            int qi_diff = qi - a[idx - 1];
            cout << b[idx - 1] + int64_t(b_diff) * qi_diff / a_diff << ' ';
        }
        cout << endl;
    }
    
    return(0);
}
