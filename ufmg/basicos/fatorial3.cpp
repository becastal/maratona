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

    vector<int> resp(1e7 + 10, 0);
    ll prev = 1;
    for (ll i = 1; i <= (ll)1e6; i++)
    {
        ll number = prev * i;
        while (number % 10 == 0)
            number /= 10;

        prev = number % (ll)1e5;
        resp[i] = number % 10;
    }

    int i = 0, n;
    while (cin >> n)
        cout << "Instancia " << ++i << endl << resp[n] << endl;
    
    return(0);
}
