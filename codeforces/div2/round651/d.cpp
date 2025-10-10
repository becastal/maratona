#include <bits/stdc++.h>
#include <ranges>
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

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int& i : v) cin >> i;

    auto da = [&](int x) -> bool {

		int res = 0;

		for (int ii = 0; ii < 2; ii++) {
			int tam = 0, agr = ii;
			for (int i = 0; i < n; i++) {
				if (!agr) {
					tam++;
					agr ^= 1;
				} else {
					if (v[i] <= x) tam++, agr ^= 1;
				}
			}

			res |= tam >= k;
		}

		return res;
    };

	auto vs = v;
	sort(vs.begin(), vs.end());
	int l = 0, r = n-1;

	while (l < r) {
		int m = (l + r) / 2;

		if (da(vs[m])) {
			r = m;
		} else {
			l = m + 1;
		}
	}
    cout << vs[l] << endl;

    return 0;
}
