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
	
	vector<int> v(n);
	for (int& i : v) cin >> i;

	int tot = (int)3e5 + 10;
	vector<int> dp(tot+1), pai(tot+1, -1), idx(tot+1, -1), jafoi(tot+1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = v[i]; j <= tot; j++) {
			if (dp[j - v[i]]) {
				if (!dp[j]) {
					pai[j] = j - v[i];
					idx[j] = i + 1;
				} else {
					jafoi[j] = 1;
				}
				dp[j] = 1;
			} 
		}
	}

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		if (!dp[x]) cout << "Impossible" << endl;
		else {
			int ok = 1;
			vector<int> res;
            for (int i = x; i != 0 and ok; i = pai[i]) {
                res.push_back(idx[i]);
				ok &= !jafoi[i];
            }
            sort(res.begin(), res.end());

			if (ok) {
				for (int i : res) cout << i << ' '; cout << endl;
			}
			else cout << "Ambiguous" << endl;
		}
	}

    return(0);
}
