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

	vector<int> R(q), Mnl(n), Mnr(n), Mxl(n), Mxr(n);
	vector<array<int, 3>> Q(q);
	for (int i = 0, a, b; i < q; i++) {
		cin >> a >> b;
		Q[i] = {a - 1, b - 1, i};
	}

	function<void(int, int, vector<array<int, 3>>&)> calc = [&](int l, int r, vector<array<int, 3>>& Qi) {
		if (l == r) {
			return;
		}

		int m = (l + r) / 2;
		Mnl[m] = Mnr[m] = Mxl[m] = Mxr[m] = A[m];
		for (int i = m-1; i >= l; i--) {
			Mnl[i] = min(A[i], Mnl[i + 1]);
			Mxl[i] = max(A[i], Mxl[i + 1]);
		}
		for (int i = m+1; i <= r; i++) {
			Mnr[i] = min(A[i], Mnr[i - 1]);
			Mxr[i] = max(A[i], Mxr[i - 1]);
		}

		vector<vector<array<int, 3>>> Qi_(2);
		for (auto [a, b, id] : Qi) {
			if (a <= m and m <= b) {
				R[id] = max(Mxr[b], Mxl[a]) - min(Mnr[b], Mnl[a]);
			} else {
				Qi_[a > m].push_back({a, b, id});
			}
		}

		calc(l, m, Qi_[0]);
		calc(m+1, r, Qi_[1]);
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

