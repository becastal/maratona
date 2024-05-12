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

bool testaMov(string& movs, int chute)
{
    int pos = chute - 1;
    while (pos < movs.size() - 1)
    {
        cout << "p: " << pos << ", max: " << endl;
        if (pos < 0) return false;
        pos += (movs[pos] == 'R' ? +chute : -1);
    }
    return true;
}

int main()
{
    _;

    int t; cin >> t;
    while (t--)
    {
        string movs; cin >> movs;
        int l = 1, r = movs.size() - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (testaMov(movs, m))
                r = m;
            else
                l = m + 1;
        }
        cout << l << endl;
    }

    return(0);
}
