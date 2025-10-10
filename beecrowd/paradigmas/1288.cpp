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

void solve() {
	int n; cin >> n;
	vector<int> v(n), p(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i] >> p[i];
	}
	int K, R; cin >> K >> R;

	vector<int> dp(K+1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = K; j >= p[i]; j--) {
			dp[j] = max(dp[j], dp[j-p[i]] + v[i]);
		}
	}

	int res = *max_element(dp.begin(), dp.end());
	cout << (res >= R ? "Missao completada com sucesso" : "Falha na missao") << endl;
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
