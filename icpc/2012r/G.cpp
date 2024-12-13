// Problema G
// Grid de Largada (1228)

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
    int n;

    while (cin >> n)
    {
        map<int, int> carros;
        vector<int> inicio(n), fim;
        
        for (int i = 0; i < n; i++)
            cin >> inicio[i], inicio[i]--;

        for (int i = 0; i < n; i++)
        {
            int j; cin >> j; j--;
            carros[j] = i;
        }

        for (int i = 0; i < n; i++)
            fim.push_back(carros[inicio[i]]);

        int ult = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (fim[i] > fim[j]) ult++;

        cout << ult << endl;
    }

    return(0);
}