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

int main()
{
    _;

   	int n, m, q; cin >> n >> m >> q;
	vector<vector<int>> M(n, vector<int>(m));
	for (auto& l : M) for (auto& c : l) cin >> c;

	vector<int> ora(m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			M[i][j] |= ora[j];
			ora[j] |= M[i][j];
		}
	}

	while (q--) {
		int mi; cin >> mi;
		int L = 0, R = n - 1;
		while (mi--) {
			int r, c; char o; cin >> r >> o >> c; r--;

			if (o == '<') {
				int le = -1, ri = n, mid;
				while (le + 1 != ri) {
					mid = (le + ri) / 2;
					if (M[mid][r] < c) le = mid;
					else ri = mid;
				}
				if (le < R) R = le;
			} else {
				int le = -1, ri = n, mid;
				while (le + 1 != ri) {
					mid = (le + ri) / 2;
					if (M[mid][r] <= c) le = mid;
					else ri = mid;
				}
				if (ri > L) L = ri;
			}
		}

		if (L <= R) cout << L + 1 << endl;
		else cout << -1 << endl;
	}
	
    return(0);
}
