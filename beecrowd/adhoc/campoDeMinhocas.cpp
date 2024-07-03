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
    int n, m; cin >> n >> m;

    vector<int> somaLinhas(n, 0);
    vector<int> somaColunas(m, 0);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int mi; cin >> mi;
            somaLinhas[i] += mi;
            somaColunas[j] += mi;
        }
    
    cout << max(*max_element(somaLinhas.begin(), somaLinhas.end()), *max_element(somaColunas.begin(), somaColunas.end())) << endl;
}
