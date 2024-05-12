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
   
    int n; cin >> n;
    vector<int> colunas(n), esq(n), dir(n);
    
    for (auto& ai : colunas)
        cin >> ai;

    esq[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        esq[i] = min(esq[i + 1] + 1, colunas[i]);

    dir[0] = 1; 
    for (int i = 1; i < n; i++)
        dir[i] = min(dir[i - 1] + 1, colunas[i]);

    int maior = 0;
    for (int i = 0; i < n; i++)
        maior = max(maior, min(dir[i], esq[i]));

    cout << maior << endl;

    return(0);
}
