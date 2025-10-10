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

int solve() {
	string s; cin >> s;
	
	vector<int> v;
	int soma = 0, dois = 0, tres = 0;
	for (char c : s) {
		soma += c - '0';	
		if (c == '2') v.push_back(2), dois++;
		if (c == '3') v.push_back(6), tres++;
	}

	int maxs = dois * 2 + tres * 6;
	vector<int> dp(maxs+1, 0);
	dp[0] = 1;

	for (int i = 0; i <= dois; i++) {
		for (int j = 0; j <= tres; j++) {
			dp[i*2+j*6] = 1;			
		}
	}

	for (int i = 0; i <= maxs; i++) {
		if (dp[i] and (soma + i) % 9 == 0) return cout << "YES" << endl, 0; 
	}

	return cout << "NO" << endl, 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
