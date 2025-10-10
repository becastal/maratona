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
	int n, m; cin >> n >> m;

	vector<int> b;
	vector<vector<int>> a(n, vector<int>(m));
	for (auto& i : a) for (auto& j : i) cin >> j, b.push_back(j);

	if (n == 1) return cout << "1 1" << endl, 0;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	int resl = -1, resr = -1;
	auto da = [&](int mi) {
		vector<int> f((1 << m), 0);
		vector<vector<int>> pos(1 << m);
		
		for (int i = 0; i < n; i++) {
			int mask = 0;
			for (int j = 0; j < m; j++) {
				if (a[i][j] >= mi) {
					mask |= (1 << j);
				}
			}
			f[mask]++;
			pos[mask].push_back(i);
		}
		
		vector<int> comple(1 << m, -1);
		for (int mask = 0; mask < (1 << m); mask++) {
			if (!pos[mask].empty()) {
				comple[mask] = pos[mask][0];
			}
		}

		for (int i = 0; i < m; i++) {
			for (int mask = 0; mask < (1 << m); mask++) {
				if (!(mask & (1<<i)) and comple[mask | (1 << i)] != -1) {
					comple[mask] = comple[mask | (1 << i)];
				}
			}
		}

		for (int mask = 0; mask < (1 << m); mask++) {
			if (pos[mask].empty()) continue;

			int preciso = ((1 << m) - 1) ^ mask;

			if (mask == (1 << m) - 1) {
				if (pos[mask].size() >= 2) {
					resl = pos[mask][0];
					resr = pos[mask][1];
					return 1;
				}
			} else {
				if (comple[preciso] != -1) {
					resl = pos[mask][0];
					resr = comple[preciso];
					return 1;
				}
			}
		}

		return 0;
	};

	int l = 0, r = (int)b.size()-1, res = -1;
	while (l <= r) {
		int mi = l + (r - l) / 2;

		if (da(b[mi])) {
			res = mi;
			l = mi + 1;
		} else {
			r = mi - 1;
		}
	}

	assert(res != -1);
	da(b[res]);
	cout << resl + 1 << ' ' << resr + 1 << endl;

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
