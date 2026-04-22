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

    map<string, int> aparicoes;
    vector<pair<string, int>> msgs;

    for (int i = 0; i < n; i++)
    {
        string pessoa; cin >> pessoa;
        aparicoes[pessoa]++;

        msgs.push_back({pessoa, aparicoes[pessoa]});
    }

    reverse(msgs.begin(), msgs.end());
    for (auto p : msgs)
        if (p.s == aparicoes[p.f]) cout << p.f << endl;

    return(0);
}