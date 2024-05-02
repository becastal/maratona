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
        int n; cin >> n;
        vector<int> v(n);
        
        for (auto& ai : v)
            cin >> ai;

        sort(v.begin(), v.end());
        vector<int> resp;

        int i = 0, j = v.size() - 1;
        while (i <= j)
        {
            if (i != j) resp.push_back(v[j]);
            resp.push_back(v[i]);
            i++, j--;
        }

        reverse(resp.begin(), resp.end());
        
        for (auto p : resp)
            cout << p << endl;

        cout << endl;
    }

    return 0;
}