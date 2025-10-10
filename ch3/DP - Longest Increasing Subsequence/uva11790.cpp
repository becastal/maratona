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

int msis(vector<int>& H, vector<int>& W) {
    int res = 0;
    int n = H.size();

    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        dp[i] = W[i];

        for (int j = 0; j < i; j++) {
            if (H[j] < H[i]) {
                dp[i] = max(dp[i], dp[j] + W[i]);
            }
        }

        res = max(res, dp[i]);
    }

    return res;
}

void solve() {
	int n; cin >> n;
	vector<int> H(n), W(n);

	for (int& i : H) cin >> i;
	for (int& i : W) cin >> i;

	int s_inc = msis(H, W);

	for (int& i : H) i = -i;
	int s_dec = msis(H, W);

	if (s_inc >= s_dec) {
		cout << "Increasing (" << s_inc << "). Decreasing (" << s_dec << ")." << endl;
	} else {
		cout << "Decreasing (" << s_dec << "). Increasing (" << s_inc << ")." << endl;
	}
}

int main()
{
    _;

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case " << t << ". ";
		solve();
	}
    
    return(0);
}
