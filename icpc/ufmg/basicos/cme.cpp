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
    int q; cin >> q;
    while (q--)
    {
        int n, distante; cin >> n;
        
        if (n <= 4) 
            distante = 4;
        else
            distante = (n % 2 == 1) ? n + 1 : n;

        cout << distante - n << endl;
    }

    return(0);
}