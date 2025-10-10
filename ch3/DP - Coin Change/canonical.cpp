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

map<int, int> ja;

int main()
{
    _;

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());

	int tot = v.back() * 2 + 10;

	vector<int> dp(tot+1, INF);
	dp[0] = 0;

	auto guloso = [&](int x) -> int {
		if (ja.count(x)) return ja[x];

		int xi = x, i = n - 1, res = 0;
		while (xi > 0 && i >= 0) {
			if (xi >= v[i]) {
				res += xi / v[i];
				xi %= v[i];
			}
			i--;
		}

		return ja[x] = (xi == 0 ? res : INF);
	};

	for (int i : v) {
		for (int j = i; j <= tot; j++) {
			dp[j] = min(dp[j], dp[j-i]+1);
		}
	}

	int ok = 1;	
	for (int j = 0; j <= tot and ok; j++) {
		ok &= (guloso(j) == dp[j]);
	}

	cout << (ok ? "canonical" : "non-canonical") << endl;
    
    return(0);
}
