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
	int n, L, R; cin >> n >> L >> R;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	sort(A.begin(), A.end());
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int l = lower_bound(A.begin() + i + 1, A.end(), L - A[i]) - A.begin();
		int r = upper_bound(A.begin() + i + 1, A.end(), R - A[i]) - A.begin();

		res += max(0, r - l);
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
