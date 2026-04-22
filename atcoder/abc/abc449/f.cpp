#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int hzao, wzao, h, w, n; cin >> hzao >> wzao >> h >> w >> n;

	vector<array<int, 4>> ev;
	for (int i = 0, r, c; i < n; i++) {
		cin >> r >> c;

		int cl = max(1LL, c - w), cr = min(wzao, c + w + 1);
		int rl = max(1LL, r - h), rr = min(wzao, r + h);

		ev.push_back({cl, 0, rl, rr});
		ev.push_back({cr, 1, rl, rr});
	}

	int tot = 0;
	set<array<int, 2>> S;

	auto add = [&](int l, int r) {
		auto it = S.lower_bound({l, r});

		if (it == S.end()) {
			S.insert({l, r});
			tot += r - l + 1;
		} else {
			
		}
	};
	auto rem = [&](int l, int r) {
				
	};
	
	int res = 0, agr = 0, ult = 1;
	for (auto [p, tp, l, r] : ev) {
		if (tp == 0) {
			add(l, r);
			if (agr++) res += tot * ult;
		} else {
			rem(l, r);
			agr--;
		}
		ult = p;
	}
	cout << ((hzao - h + 1) * (wzao - w + 1) - res) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

