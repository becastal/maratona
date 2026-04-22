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

const int mod = 1e8;
int n0, n1, k0, k1;
map<tuple<int, int, int, int>, int> memo;

int dp (int j, int k, int q0, int q1)
{
	if (q0 < 0 or q1 < 0) return 0;
	tuple<int, int, int, int> tup = {j, k, q0, q1};
	if (memo.find(tup) != memo.end()) return memo[tup];
	if (!q0 and !q1) return memo[tup] = 1;

	if (j)
	{
		if (k >= k1) return memo[tup] = dp(!j, 1, q0 - 1, q1) % mod;
		else return memo[tup] = dp(!j, 1, q0 - 1, q1) % mod + dp(j, k + 1, q0, q1 - 1) % mod;
	}
	else
	{
		if (k >= k0) return memo[tup] = dp(!j, 1, q0, q1 - 1) % mod;
		else return memo[tup] = dp(!j, 1, q0, q1 - 1) % mod + dp(j, k + 1, q0 - 1, q1) % mod;
	}
}

int main()
{
    _;

	cin >> n0 >> n1 >> k0 >> k1;
	
	cout << (dp(1, 1, n0, n1 - 1) % mod + dp(0, 1, n0 - 1, n1) % mod) % mod << endl;
    
    return(0);
}
