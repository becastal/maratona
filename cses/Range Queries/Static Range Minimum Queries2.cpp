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
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<array<int, 3>> B(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		B[i] = {l-1, r-1, i};
	}

	vector<int> L(n), R(n), res(q);
	function<void(int, int, vector<array<int, 3>>)> f = [&](int l, int r, vector<array<int, 3>> Q) {
		if (!Q.size()) return;
		if (l == r) {
			for (auto [l, r, id] : Q) res[id] = A[l];
			return;
		}

		int m = (l + r) / 2;
		L[m] = A[m];
		for (int i = m-1; i >= l; i--) {
			L[i] = min(A[i], L[i+1]);
		}
		R[m+1] = A[m+1];
		for (int i = m+2; i <= r; i++) {
			R[i] = min(A[i], R[i-1]);
		}

		vector falta(2, vector<array<int, 3>>());
		for (auto [l, r, id] : Q) {
			if (l <= m and m < r) {
				res[id] = min({L[l], R[r], A[m]});
				continue;
			}
			falta[l > m].push_back({l, r, id});
		}
		f(l, m, falta[0]);
		f(m+1, r, falta[1]);
	};
	f(0, n-1, B);
	for (int i : res) cout << i << endl;

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
