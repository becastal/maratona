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

const int mod = 1e9 + 7;

int main()
{
    _;

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	// de quantas maneiras diferentes eu consigo somar k com n valores, mas ni nao pode ser maior que vi;
	vector<int> dp(k + 1, 0);
	
    
	cout << dp[k] << endl;

    return(0);
}
