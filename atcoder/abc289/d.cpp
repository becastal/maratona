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
	vector<int> a(n);
	for (int& i : a) cin >> i;

	int m; cin >> m;
	vector<int> b(m);
	set<int> B;
	for (int& i : b) cin >> i, B.insert(i);

	int x; cin >> x;

	vector<int> dp(x+1, 0);
	dp[0] = 1;
	
	for (int j = 1; j <= x; j++) {
		if (B.count(j)) dp[j] = 0;
		else {
			for (int i : a) {
				if (j >= i) dp[j] |= dp[j-i];
			}
		}
	}

	cout << (dp[x] ? "Yes" : "No") << endl;
    
    return(0);
}
