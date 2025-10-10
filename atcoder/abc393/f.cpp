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
    
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<vector<pair<int, int>>> qs(n);
	for (int i = 0, r, x; i < q; i++) {
		cin >> r >> x;
		qs[--r].emplace_back(i, x);
	}

	vector<int> res(q), dp(n, INF);

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(dp.begin(), dp.end(), v[i]);
		*it = v[i];

		for (auto [id, x] : qs[i]) {
			res[id] = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
		}
	}

	for (auto i : res) cout << i << endl;

    return(0);
}
