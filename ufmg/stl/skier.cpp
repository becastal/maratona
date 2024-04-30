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
    map<char, pair<int, int>> mov = { {'N', {-1, 0}}, {'S', {1, 0}}, {'W', {0, -1}}, {'E', {0, 1}} };
    int t; cin >> t;
 
    while (t--)
    {
        set<pair< pair<int, int>, pair<int, int> >> caminhosFeitos;
        pair<int, int> atual = {0, 0};
        int tempo = 0;
 
        string movimentos; cin >> movimentos;
        for (auto c : movimentos)
        {
            pair<int, int> anterior = atual;
            pair<int, int> posterior = {atual.f + mov[c].f, atual.s + mov[c].s};
 
            if (!caminhosFeitos.count({anterior, posterior}))
                tempo += 5;
            else
                tempo++;
 
            caminhosFeitos.insert({anterior, posterior});
            caminhosFeitos.insert({posterior, anterior});
            atual = posterior;
        }
        cout << tempo << endl;
    }

    return 0;
}