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

	int n, x; cin >> n >> x;
	vector<int> s(n), c(n), p(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> c[i] >> p[i];
	}

	vector<vector<double>> dp((1 << n), vector<double>(x+1, 0.0));

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) continue;

			for (int ii = x - c[j]; ii >= 0; ii--) {
				dp[i | (1 << j)][ii] = max(dp[i | (1 << j)][ii], 
								dp[i][ii + c[j]] + p[j] * s[j]);
			}
		}
	}

	cout << fixed << setprecision(15);
	cout << *max_element(dp[(1 << n)-1].begin(), dp[(1 << n)-1].end()) << endl;
    
    return(0);
}
