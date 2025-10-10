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
	setIO("angry");

	int n, k; cin >> n >> k;

	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());

	auto da = [&](ll m) {

		int cont = 0;
		for (int l = 0, r; l < n; l = r) {
			r = l + 1;

			while (r < n and a[r] <= a[l] + 2 * m) {
				r++;
			}
			cont++;
		}

		return cont <= k;
	};

	ll l = 1, r = (ll)1e12, res = r;
	while (l <= r) {
		ll m = l + (r - l) / 2;

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
