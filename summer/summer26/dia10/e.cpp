#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 1e9+7;
const int MAX = 2e5+10;
int onde[45];

namespace seg {
	int n, m;
	int seg[2*MAX][20];

	void combina(int* C, int* A, int* B) {
		for (int i = 0; i < m; i++) {
			C[i] = A[i] + B[i];	
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				C[onde[i + j]] += A[i] * B[j] % mod;
			}
		}

		for (int i = 0; i < m; i++) {
			C[i] %= mod;
		}
	}

	void build() {
		for (int i = n - 1; i; i--) combina(seg[i], seg[2*i], seg[2*i+1]);
	}

	void query(int* res, int a, int b) {
		for (a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			int temp[20];
			for (int j = 0; j < m; j++) {
				temp[j] = res[j];
			}

			if (a % 2 == 1) combina(res, temp, seg[a]);

			for (int j = 0; j < m; j++) {
				temp[j] = res[j];
			}

			if (b % 2 == 0) combina(res, temp, seg[b]);
		}
	}
};

signed solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	for (int i = 0; i < 40; i++) {
		onde[i] = i % m;
	}
	
	memset(seg::seg, 0, sizeof(seg::seg));
	seg::n = n, seg::m = m;
	for (int i = 0; i < n; i++) {
		seg::seg[i + n][A[i] % m] = 1;
	}
	seg::build();

	int res[20];
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r; l--, r--;

		memset(res, 0, sizeof(res));
		seg::query(res, l, r);
		cout << res[0] + 1 << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

