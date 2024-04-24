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
    int n; cin >> n;
    while (n--)
    {
        double a, b; cin >> a >> b;
        string mensagem;
        if (b == 0.0) 
            cout << "divisao impossivel" << endl;
        else
            cout << a / b << fixed << setprecision(1) << endl;
    }

    return(0);
}