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

vector<int> pipocas;
int n, c, t;

bool possivel(ll chute)
{
    int comp = 1;
    ll resta = t*chute;
    for (int i = 0; i < n; i++)
    {
        if (resta >= pipocas[i])
            resta -= pipocas[i];
        else
        {
            comp++;
            resta = t*chute;
            i--;
        }
        if (comp > c) return false;
    }   
    return true;
}

int main()
{
    _;

    pipocas = vector<int>(n);
    for (auto& p : pipocas)
        cin >> p;

    int l = 0, r = 1e9+1;
    while (l < r)
    {
        int m = (l + r) / 2;
        
        if (!possivel(m))
            l = m + 1;
        else
            r = m;
    }        

    cout << l << endl;

    return(0);
}
