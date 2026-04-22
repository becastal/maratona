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

vector<tuple<char, int, int>> operacoes;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;

        int resto = b % 10;

        if (resto)
            swap(a, b);
        else 
            resto = a % 10;

        cout << a - resto << " x " << b << " + " << resto << " x " << b << endl;
    }

    return(0);
}
