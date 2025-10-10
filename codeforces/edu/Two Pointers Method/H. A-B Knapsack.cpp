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
	ll n, m, s, wa, wb;
	cin >> n >> m >> s >> wa >> wb;

	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());

	ll res = 0, sa = 0, sb = accumulate(B.begin(), B.end(), 0LL);
	for (int l = 0, r = m; l <= n; l++) {
		while (r > 0 and wa * l + wb * r > s) {
			sb -= B[--r];
		}

		if (wa * l + wb * r <= s) res = max(res, sa + sb);
		if (l < n) sa += A[l];
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
