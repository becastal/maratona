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
	int n, k; cin >> n >> k;

	vector<int> v(n);
	for (int& i : v) cin >> i;

	auto da = [&](int m) {
		int res = 1, agr = m+1;

		vector<int> vi(m+1, 1);
		for (int i : v) {
			if (i <= m and vi[i]) vi[i] = 0, agr--;
			if (!agr) {
				res++;
				fill(vi.begin(), vi.end(), 1);
				agr = m+1;
			}
		}

		return res <= k;
	};

	int l = 0, r = n;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			r = m-1;
		} else {
			l = m+1;
		}
	}
	cout << l << endl;
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
