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
    int n, k; cin >> n >> k;

	vector<int> v(n), dp((int)5e5+10, 0);
    int mx = 0, cont = 0;
    for (int& i : v) {
		cin >> i;
        if (i == k) ++cont;
        else dp[i] = max(dp[i], cont) + 1;
        mx = max(mx, dp[i] - cont);
    }

	cout << cont + mx << endl;

    return(0);
}
