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

    vector<int> v(n);
    for (auto& ni : v)
        cin >> ni;
    
    vector<int> soma(n + 1), maior(n + 1);
    soma[0] = maior[0] = 0;

    for (int i = 0; i < n; i++)
    {
        soma[i + 1] = soma[i] + v[i];
        maior[i + 1] = max(maior[i], soma[i + 1]);
    }

    int resp = 0;
    for (int i = 0; i <= n; i++)
        resp = max(resp, maior[i] + (soma[n] - soma[i]));

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = max(0, temp + v[i]);
        resp = max(resp, temp);
    }

    cout << resp << endl;

    return 0;
}
