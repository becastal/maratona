#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<array<int, 3>> Q(q);
	for (int i = 0; i < q; i++) {
		cin >> Q[i][0] >> Q[i][1]; Q[i][0]--, Q[i][1]--;
		Q[i][2] = i;
	}

	vector<int> R(q), M(n);
	function<void(int, int, vector<array<int, 3>>&)> calc = [&](int l, int r, vector<array<int, 3>>& qi) {
		if (l == r) {
			for (auto [a, b, id] : qi) {
				R[id] = A[a];
			}
			return;
		}

		int m = (l + r) / 2;
		M[m] = A[m];
		for (int i = m-1; i >= l; i--) {
			M[i] = max(M[i+1], A[i]);
		}

		for (int i = m+1; i <= r; i++) {
			M[i] = max(M[i-1], A[i]);
		}

		vector<vector<array<int, 3>>> q_(2);
		for (auto [a, b, id] : qi) {
			if (a <= m and m < b) {
				R[id] = max(M[a], M[b]);
			} else {
				q_[a > m].push_back({a, b, id});
			}
		}
		calc(l, m, q_[0]);
		calc(m+1, r, q_[1]);
	};
	calc(0, n-1, Q);

	for (int i : R) {
		cout << i << endl;
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

