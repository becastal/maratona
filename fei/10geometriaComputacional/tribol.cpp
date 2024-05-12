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
    int t; cin >> t;
    while (t--)
    {
        map<char, int> placar = {{'B', 0}, {'R', 0}, {'G', 0}};
        map<char, map<char, int>> gol = {{'B', {{'R', 2}, {'G', 1}}}, {'R', {{'G', 2}, {'B', 1}}}, {'G', {{'B', 2}, {'R', 1}}}};
        int p; cin >> p;
        for (int i = 0; i < p; i++)
        {
            char fez, tomou; cin >> fez >> tomou;
            placar[fez] += gol[fez][tomou];
        }

        if (placar['B'] == placar['R'] && placar['B'] == placar['G'])
            cout << "trempate" << endl;
        else if (placar['B'] > placar['R'] && placar['B'] > placar['G'])
            cout << "blue" << endl;
        else if (placar['R'] > placar['B'] && placar['R'] > placar['G'])
            cout << "red" << endl;
        else if (placar['G'] > placar['B'] && placar['G'] > placar['R'])
            cout << "green" << endl;
        else if (placar['B'] == placar['R'] || placar['B'] == placar['G'] || placar['R'] == placar['G'])
            cout << "empate" << endl;
   }
    
    return(0);
}
