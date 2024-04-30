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
    vector<int> l(128, 0);

    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        l[c]++;
    }

    int uns = 0;
    while (l['o'] >= 1 && l['n'] >= 1 && l['e'] >= 1)
        uns++, l['o']--, l['n']--, l['e']--;

    int zeros = 0;
    while (l['z'] >= 1 && l['e'] >= 1 && l['r'] >= 1 && l['o'] >= 1)
        zeros++, l['z']-- , l['e']-- , l['r']-- , l['o']--;

    for (int i = 0; i < uns; i++)
        cout << "1 ";

    for (int i = 0; i < zeros; i++)
        cout << "0 ";

    cout << endl;

    return 0;
}