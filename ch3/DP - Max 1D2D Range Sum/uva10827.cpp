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
	int n; cin >> n;

	vector<vector<ll>> a(n, vector<ll>(n)), b(2 * n, vector<ll>(2 * n, 0LL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			b[i][j] = a[i % n][j % n];
		}
	}

	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << b[i][j] << '\t';
		}
		cout << endl;
	}

	for (int i = 0; i < 2 * n; i++) {
		for (int j = 1; j < 2 * n; j++) {
			b[i][j] += b[i][j - 1];
		}
	}

	ll res = -LINF;	
	pair<int, int> pA, pB;

	for (int i = 0; i < 2 * n; i++) {
		for (int j = i; j < 2 * n and j - i < n; j++) {
			ll subRec = 0;
			int cmc = 0;

			for (int ii = 0; ii < 2 * n; ii++) {
				if (ii - cmc >= n) {
					subRec -= b[cmc][j] - (i ? b[cmc][i - 1] : 0LL);
					cmc++;
				}
				ll currSum = b[ii][j] - (i ? b[ii][i - 1] : 0LL);
				if (subRec <= 0) {
					subRec = currSum;
					cmc = ii;
				} else {
					subRec += currSum;
				}
				if (subRec > res) {
					res = subRec;

					pA = {cmc, i};
					pB = {ii, j};
				}
			}
		}
	}

	cout << res << endl;
	cout << "(" << pA.f << ", " << pA.s << ")" << endl;
	cout << "(" << pB.f << ", " << pB.s << ")" << endl;
}

int main() {
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}

    return 0;
}

