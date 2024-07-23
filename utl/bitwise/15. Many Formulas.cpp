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
    string s; cin >> s;
    ll res = 0;
    int n = s.size();
	for (int x = 0; x < (1 << (n - 1)); x++)
	{
        ll atual = 0;
		for (int i = 0; i < n; i++)
		{
            atual *= 10;
            atual += s[i] - '0';
            if ((x&(1<<i)) == 0) {
                res += atual;
                atual = 0;
            }
        }
        res += atual;
    }
    cout << res << endl;
    return 0;
}
