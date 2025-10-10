#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve(int n) {
    vector<tuple<int, int, int>> v;

    for (int i = 0, x, y, z; i < n; i++) {
        cin >> x >> y >> z;
        v.emplace_back(x, y, z);
        v.emplace_back(x, z, y);
        v.emplace_back(y, x, z);
        v.emplace_back(y, z, x);
        v.emplace_back(z, x, y);
        v.emplace_back(z, y, x);
    }

	sort(v.begin(), v.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) {
        auto [xa, ya, za] = a;
        auto [xb, yb, zb] = b;
		return xa < xb;
	});

    int N = v.size(), res = 0;
    vector<int> dp(N, 0);

    for (int i = 1; i < N; i++) {
        auto [xi, yi, zi] = v[i];
        dp[i] = zi;

        for (int j = 0; j < i; j++) {
            auto [xj, yj, zj] = v[j];

            if (xi > xj and yi > yj) {
                dp[i] = max(dp[i], dp[j] + zi);
            }
        }

        res = max(res, dp[i]);
    }

    cout << res << endl;
}

int main() {
    _;

    int n, t = 1;
    while (cin >> n && n) {
        cout << "Case " << t++ << ": maximum height = ";
        solve(n);
    }

    return(0);
}
