#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll ai, aj, bi, bj, n; cin >> ai >> aj >> bi >> bj >> n;	

	int m1, m2; cin >> m1 >> m2;
	vector<pair<char, int>> A(m1), B(m2);

	for (auto& [a, b] : A) cin >> a >> b;
	for (auto& [a, b] : B) cin >> a >> b;

	map<char, pair<int, int>> movs = {
		{'D', {1, 0}},
		{'U', {-1, 0}},
		{'R', {0, 1}},
		{'L', {0, -1}}
	};
	auto f = [&](char ad, char bd, int v) {
		auto [dai, daj] = movs[ad];
		auto [dbi, dbj] = movs[bd];
	
        ll rx = ai - bi;
        ll ry = aj - bj;
        ll vx = (ll)dai - (ll)dbi;
        ll vy = (ll)daj - (ll)dbj;
        ll cont = 0;

        if (vx == 0 and vy == 0) {
            if (rx == 0 && ry == 0) cont = v;
        } else if (vx == 0) {
            if (rx == 0) {
                if ((-ry) % vy == 0) {
                    ll t = (-ry) / vy;
                    if (1 <= t && t <= v) cont = 1;
                }
            }
        } else if (vy == 0) {
            if (ry == 0) {
                if ((-rx) % vx == 0) {
                    ll t = (-rx) / vx;
                    if (1 <= t && t <= v) cont = 1;
                }
            }
        } else {
            if ((-rx) % vx == 0) {
                ll t = (-rx) / vx;
                if (1 <= t && t <= v) {
                    if (ry + t * vy == 0) cont = 1;
                }
            }
        }

		ai += v * dai, aj += v * daj;
		bi += v * dbi, bj += v * dbj;
		return cont;
	};

	ll res = 0;
	for (int i = 0, j = 0; i < m1 and j < m2; ) {
		auto& [ad, af] = A[i];
		auto& [bd, bf] = B[j];

		int mn = min(af, bf);
		res += f(ad, bd, mn);
		if ((af -= mn) == 0) i++;
		if ((bf -= mn) == 0) j++;
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

