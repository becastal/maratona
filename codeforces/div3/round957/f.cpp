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
	int n, x; cin >> n >> x;
	vector<int> usei(x+1, 0), ehdiv(x+1, 0);

	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ehdiv[i] = 1;
			if (x / i != i) ehdiv[x / i] = 1;
		}
	}

	int res = 1;
	vector<int> agr = {1};
	usei[1] = 1;
	for (int i = 0, ai; i < n; i++) {
		cin >> ai;
		if (ai > x or !ehdiv[ai]) continue;

		vector<int> agr_;
		int ok = 1;
		for (int d : agr) {
			if ((ll)d * ai <= x and ehdiv[d * ai] and !usei[d * ai]) {
				agr_.push_back(d * ai);
				usei[d * ai] = 1;
				if (d * ai == x) ok = 0;
			}
		}
		for (int d : agr_) {
			agr.push_back(d);
		}

		if (!ok) {
			res++;

			for (int d : agr) {
				usei[d] = 0;
			}
			usei[1] = usei[ai] = 1;
			agr = { 1, ai };
		}
	}
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
