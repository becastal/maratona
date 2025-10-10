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

	int V, n; 
	while (cin >> V >> n and n) {
		vector<int> v(n);
		for (int& i : v) cin >> i;

		bitset<(int)1e5+10> dp;
		dp[0] = 1;

		for (int i : v) {
			dp |= dp << i;
		}

		cout << (dp[V] ? "sim" : "nao") << endl;
	}
    
    return(0);
}
