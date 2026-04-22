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

bool solve(int n)
{
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) 
            return false;
    return true;
}

int main()
{
    _;
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;
        cout << (solve(n) ? "Prime" : "Not Prime") << endl;
    }
}
