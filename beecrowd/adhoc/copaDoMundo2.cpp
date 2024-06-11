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

	int t, n;
    while(cin >> t >> n and t)
    {
        int tot = 3 * n;
        int soma = 0;
        for(int i = 0; i < t; i++)
        {
            string s;
            int point;
            cin >> s >> point;
            soma += point;
        }
        cout << tot - soma << endl;
    }
    
    return(0);
}
