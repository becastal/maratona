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

	int n;
	while (cin >> n and n) {
		vector<int> v(n), p(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i] >> p[i];
		}

		int M; cin >> M;
		vector<int> dp(M+1, 0);

		for (int i = 0; i < n; i++) {
			for (int j = M; j >= p[i]; j--) {
				dp[j] = max(dp[j], dp[j-p[i]] + v[i]);
			}
		}

		cout << *max_element(dp.begin(), dp.end()) << endl;
	}
    
    return(0);
}
