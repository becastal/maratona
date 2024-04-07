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

vector<vector<char>> mapa;
vector<pair<int, int>> robos;
vector<pair<int, int>> destinos;
int n;

void bfs()
{
    queue<pair<int, int>> q;
    
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
        {
            cin >> mapa[i][j];
            if (mapa[i][j] >= 'A' && mapa[i][j] <= 'C') robos.push_back({i, j});
            if (mapa[i][j] == '#') destinos.push_back({i, j});
        }

        
    } 
    return(0);
}
