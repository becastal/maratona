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

void solve(int P, int n) {
	vector<int> p(n), v(n), dp(P+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> v[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = P; j >= p[i]; j--) {
			dp[j] = max(dp[j], dp[j-p[i]] + v[i]);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << endl << endl;
}

int main()
{
    _;

	int P, n, cas = 0;
	while (cin >> P >> n and P) {
		cout << "Teste " << ++cas << endl;
		solve(P, n);
	}
    
    return(0);
}
