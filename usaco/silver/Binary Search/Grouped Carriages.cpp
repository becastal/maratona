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

int solve() {
	int n; cin >> n;
	vector<int> a(n), d(n);
	for (int& i : a) cin >> i;
	for (int& i : d) cin >> i;

	auto da = [&](int z) {

		vector<vector<int>> ev(n);
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				ev[max(0, i - d[i])].push_back(i);
			}
		}

		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < n; i++) {
			for (int j : ev[i]) {
				pq.emplace(-(j + d[j]), a[j]);
			}

			int cap = z;
			while (cap and !pq.empty()) {
				auto [r, cont] = pq.top(); pq.pop();

				if (-r < i) return 0;
				int usei = min(cap, cont);
				cap -= usei, cont -= usei;
				if (cont) pq.emplace(r, cont);
			}
		}

		return int(pq.empty());
	};

	int l = 0, r = *max_element(a.begin(), a.end()), res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			res = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
