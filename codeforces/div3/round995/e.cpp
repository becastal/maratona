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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);

	priority_queue<pair<int, int>> pq;
    for (int& i : a) cin >> i, pq.emplace(-i, 1);
    for (int& i : b) cin >> i, pq.emplace(-i, 0);

	ll res = 0;
	int ruim = 0, dentro = n;
	int ai, tp;
	while (pq.size()) {
		ai = pq.top().f, tp = pq.top().s; pq.pop();
		ai = -ai;

		if (ruim <= k) {
			res = max(res, (ll)dentro * ai);
		}
		ruim += (tp ? 1 : -1);
		dentro -= !tp;
	}

	cout << res << endl;
}

int main() {
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

