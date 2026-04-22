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
    vector<int> pot(31, 1);
    
    for (int i = 1; i <= 31; i++)
        pot[i] = pot[i - 1] * 2;

    while (t--)
    {
        int n; cin >> n;

        int a = pot[n], b = 0;
        for (int i = 1; i < n / 2; i++)
            a += pot[i];
        
        for (int i = n / 2; i < n; i++)
            b += pot[i];

        cout << abs(a - b) << endl;
    }

    return(0);
}