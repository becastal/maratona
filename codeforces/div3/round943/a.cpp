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
        int n; cin >> n;
 
        int maior = -1;
        vector<int> x(n-1);
        for (auto& xi : x)
        {
            cin >> xi;
            maior = max(maior, xi);
        }
 
        vector<int> a(n);
        a[0] = maior + 1;
        for (int i = 0; i < n - 1; i++)
            a[i+1] = a[i] + x[i];
 
        for (auto ai : a)
            cout << ai << " ";
        cout << endl;
    }
 
    return 0;
}
