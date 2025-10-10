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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("socdist");

	int n, m; cin >> n >> m;
	vector<array<ll, 2>> a(m);

	for (auto& [li, ri] : a) {
		cin >> li >> ri;
	}
	sort(a.begin(), a.end());

	auto da = [&](ll d) {
		int cont = 1;

		ll ult = a[0][0];
		for (int l = 1, r = 0; l < n; l++) {
			ll prox = ult + d;

			while (r < m and a[r][1] < prox) {
				r++;
			}

			if (r == m) return 0;
			ult = max(prox, a[r][0]);
		}

		return 1;
	};

	ll l = 0, r = (ll)1e16, res = r;
	while (l <= r) {
		ll mi = l + (r - l) / 2;

		if (da(mi)) {
			res = mi;
			l = mi + 1;
		} else {
			r = mi - 1;
		}
	}
	cout << res << endl;

    return(0);
}
