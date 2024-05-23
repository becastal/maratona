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

int c, n;

int main()
{
    _;
    cin >> c >> n;

    vector<int> a(c, 0);
    for (int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        a[ai] = 1;
    }
    
    for (int i = 1; i < c; i++)
        a[i] += a[i - 1];
       
    int i, j;
    for (i = 0; i < (c / n); i++)
    {
        for (j = 0; j < n - 1; j++)
            if(a[i + (j + 1) * (c / n) - 1] != a[i + j * (c / n) - 1] + 1)
                break;
        if (j == n - 1) break;
    }
       
    cout << (i < (c / n) ? "S" : "N") << endl;

    return(0);
}
