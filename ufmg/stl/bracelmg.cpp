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

bool solve(int idx, string& inha, string& ona)
{
    for (int i = 0; i < inha.size(); i++)
        if (inha[i] != ona[idx + i]) return false;

    return true;
}

int main()
{
    _;
    int t; cin >> t;
    while (t--)
    {
        string inha, ona; cin >> inha >> ona;
        string inhaR; reverse_copy(inha.begin(), inha.end(), back_inserter(inhaR));
        bool presente;

        for (int i = 0; i < inha.size(); i++)
            ona += ona[i];

        for (int i = 0; i < ona.size(); i++)
        {
            presente = solve(i, inha, ona) || solve(i, inhaR, ona);
            if (presente) break;
        }

        cout << (presente ? "S" : "N") << endl;
    }

    return(0);
}