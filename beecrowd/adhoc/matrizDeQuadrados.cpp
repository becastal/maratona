#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;
typedef __int128 ll;

const int INF = 0x3f3f3f3f;
const ll LINF = (__int128)1 << 127;

int dig(ll x)
{
    int res = 0;
    while (x)
    {
        res++;
        x /= 10;
    }
    return res;
}

void print_int128(__int128 x) {
    if (x == 0) {
        cout << "0";
        return;
    }
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    string res = "";
    while (x > 0) {
        res += (x % 10) + '0';
        x /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res;
}

int main()
{
    _;

    int t; cin >> t; 
    int x = 4;
    while (t--)
    {
        int n; cin >> n;
        cout << "Quadrado da matriz #" << x++ << ':' << endl;
        vector<vector<ll>> m(n, vector<ll>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                long long temp;
                cin >> temp;
                m[i][j] = (__int128)temp * temp;
            }

        vector<int> maior(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                maior[j] = max(maior[j], dig(m[i][j]));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {
                cout << setw(maior[j]);
                print_int128(m[i][j]);
                cout << ' ';
            }
            cout << endl;
        }
    }
    
    return 0;
}

