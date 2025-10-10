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

const int MAX = 1e5+10;
vector<vector<int>> divs(MAX), oc(MAX);

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) {
		for (int j = i; j <= lim; j += i) {
			divs[j].push_back(i);
		}
	}
}

int solve() {
	int n, q; cin >> n >> q;
	vector<int> v(n);

	for (auto& oc_ : oc) {
		oc_.clear();
	}

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		oc[v[i]].push_back(i);
	}

	for (auto& oc_ : oc) {
		sort(oc_.begin(), oc_.end());
	}

	while (q--) {
		int k, l, r; cin >> k >> l >> r; l--, r--;
		int ult = l;

		ll res = 0;
		while (k) {
			int ml = INF;
            for (int d : divs[k]) {
                if (oc[d].empty()) continue;

				auto it = lower_bound(oc[d].begin(), oc[d].end(), ult);
				if (it != oc[d].end() and *it <= r) {
					ml = min(ml, *it);
				}
            }

			if (ml == INF) {
				res += (ll)k * (r - ult + 1);
				break;
			}

			res += (ll)k * (ml - ult);	
			while (k % v[ml] == 0) {
				k /= v[ml];
			}

			res += k;
			ult = ml + 1;
		}
		cout << res << endl;
	}

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
