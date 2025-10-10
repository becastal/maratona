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
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	assert(is_sorted(A.begin(), A.end()));

	auto da = [&](int mid) {
		int cont = k;
		for (int i = 0, ult = -(mid + 10); i < n and cont; i++) {
			if (A[i] - ult > mid) {
				cont--;
				ult = A[i];
			}
		}
		return !cont;
	};

	int l = 0, r = (int)1e9+10, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (!da(m)) {
			r = m - 1;
			res = m;
		} else {
			l = m + 1;
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
