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
	int n, q; cin >> n >> q;
	vector<vector<ll>> v(1001, vector<ll>(1001, 0)), pre(1010, vector<ll>(1001, 0));
	
	for (int i = 0, h, w; i < n; i++) {
		cin >> h >> w;
		v[h][w] += h * w;
	}
		

	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			pre[i][j] = v[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}

    auto query = [&](int hi, int wi, int hj, int wj) {
		hi++, wi++, hj--, wj--;	
        return pre[hj][wj] - pre[hj][wi-1] - pre[hi-1][wj] + pre[hi-1][wi-1];
    };

	for (int i = 0, hi, wi, hj, wj; i < q; i++) {
		cin >> hi >> wi >> hj >> wj;
		cout << query(hi, wi, hj, wj) << endl;
	}
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
