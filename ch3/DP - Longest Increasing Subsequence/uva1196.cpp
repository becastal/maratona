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
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].f >> v[i].s;
		}
		sort(v.begin(), v.end());
		vector<int> dp(n, 1);

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (v[j].f <= v[i].f and v[j].s <= v[i].s) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}

		cout << *max_element(dp.begin(), dp.end()) << endl;
	}
	cout << '*' << endl;
    
    return(0);
}
