#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<pair<int, int>> A(n);
	for (auto& [a, b] : A) cin >> a >> b;

	int res = INF;
	for (int ii = 0; ii < 2; ii++) {
		sort(all(A));
		vector<int> B(n);
		B[n-1] = A[n-1].s;

		for (int i = n-2; i >= 0; i--) {
			B[i] = max(A[i].s, B[i+1]);
		}

		set<int> S;
		for (int l = 0, r; l < n; l = r) {
			int m1 = A[l].f;

			r = l + 1;
			while (r < n and A[l].f == A[r].f) r++;
			for (int i = l; i < r-1; i++) S.insert(A[i].s);

			int m2 = (r < n ? B[r] : -INF);
			res = min(res, abs(m1 - m2));

			auto it = S.lower_bound(m1);
			if (it != S.end() and *it >= m2) res = min(res, abs(m1 - *it));
			if (it != S.begin() and *prev(it) >= m2) res = min(res, abs(m1 - *prev(it)));
			S.insert(A[r-1].s);
		}

		for (auto& [a, b] : A) swap(a, b);
	}

	//dbg(res);
	if (res == INF) res = abs(A[0].f - A[0].s);
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

