#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef __int128_t i128;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	ll p; cin >> p;

	vector<int> A(n);
	for (int& i : A) cin >> i;
	for (int i = 0; i < n; i++) {
		A.push_back(A[i]);
	}

	auto da = [&](int i, i128 t) {
		i128 s = i128(t / n) * i128(accumulate(A.begin() + i, A.begin() + i + n, 0LL))
					 + i128(accumulate(A.begin() + i, A.begin() + i + (t % n), 0LL));
		return s >= p;
	};

	i128 res = LINF, pos = -1;
	for (int i = 0; i < n; i++) {
		i128 l = 1, r = (i128)1e18, agr = LINF;

		while (l <= r) {
			ll m = l + (r - l) / 2;
			
			if (da(i, m)) {
				agr = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		};

		if (res > agr) {
			res = agr;
			pos = i;
		}
	}

	ll pos_ = pos, res_ = res;
	cout << pos_ + 1 << ' ' << res_ << endl;

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
