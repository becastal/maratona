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

int n, k;
vector<int> h, memo;

int dp(int i)
{
	if (i == 0) return 0;
	if (memo[i] != -1) return memo[i];

	int res = INF;
	for (int j = max(0, i - k); j < i; j++)
		res = min(res, dp(j) + abs(h[j] - h[i]));

	memo[i] = res;
	return res;
}

int main()
{
    _;

	cin >> n >> k;
	h.resize(n), memo.assign(n, -1);
	for (int& hi : h)
		cin >> hi;

	cout << dp(n - 1) << endl;
    
    return(0);
}
