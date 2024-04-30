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
    map<char, pair<int, int>> mov = { {'N', {-1, 0}}, {'S', {1, 0}}, {'W', {0, -1}}, {'E', {0, 1}} };
    int t; cin >> t;

    while (t--)
    {
        set<pair<int, int>> posicoes;
        pair<int, int> atual = {0, 0};
        posicoes.insert(atual);
        int tempo = 0;

        string movimentos; cin >> movimentos;
        for (auto c : movimentos)
        {
            atual.f += mov[c].f;
            atual.s += mov[c].s;

            if (!posicoes.count(atual))
                tempo += 5;
            else
                tempo++;

            posicoes.insert(atual);
        }
        cout << tempo << endl;
    }
    
    return(0);
}