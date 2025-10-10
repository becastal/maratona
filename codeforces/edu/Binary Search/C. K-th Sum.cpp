#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;

	vector<int> A(n), B(n);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;
	sort(all(A));
	sort(all(B));

	auto da = [&](int mid) {
		ll res = 0;
		for (int l = 0, r = n-1; l < n; l++) {
			while (r >= 0 and A[l] + B[r] > mid) {
				r--;
			}
			if (r < 0) break;

			res += (r + 1);
		}
		return res >= k;
	};

	int l = A.front() + B.front(), r = A.back() + B.back(), res = r;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
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
