#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	int tam = ceil(sqrt(n));

	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<vector<int>> B(tam);
	for (int i = 0; i < tam; i++) {
		for (int j = i * tam; j <= min(n-1, (i + 1) * tam - 1); j++) {
			B[i].push_back(A[j]);
		}
		sort(all(B[i]));
	}

	int q; cin >> q;
	while (q--) {
		int tp; cin >> tp;

		if (!tp) {
			int l, r, x; cin >> l >> r >> x; l--, r--;
			int l_ = l / tam, r_ = r / tam, res = 0;
			
			if (l_ == r_) {
				for (int i = l; i <= r; i++) {
					res += (A[i] >= x);
				}
				cout << res << endl;
			} else {
				for (int i = l, fim = (l_ + 1) * tam - 1; i <= fim; i++) {
					res += (A[i] >= x);
				}

				for (int i = l_ + 1; i <= r_ - 1; i++) {
					res += B[i].end() - lower_bound(all(B[i]), x);
				}

				for (int i = r_ * tam; i <= r; i++) {
					res += (A[i] >= x);
				}

				cout << res << endl;
			}
		} else {
			int a, b; cin >> a >> b; a--;
			int i = a / tam;

			int pos = lower_bound(all(B[i]), A[a]) - B[i].begin();
			B[i][pos] = b;
			A[a] = b;
			sort(all(B[i]));
		}
	}

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

