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
    vector<int> predios(n);
    
    for (auto& ai : predios)
       cin >> ai;

    int maior = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            maior = max(maior, predios[i] + (j - i) + predios[j]);

    cout << maior << endl; 
        
    return(0);
}
