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
    vector<int> alturas(n);

    int quero; cin >> quero;
    for (auto& ai : alturas)
        cin >> ai;

    int res = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int diferenca = quero - alturas[i];
        alturas[i] += diferenca;
        alturas[i + 1] += diferenca;
        res += abs(diferenca);
    }
    cout << res << endl;

    return(0);
}
