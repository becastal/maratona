#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; ll u;
	cin >> n >> q >> u; 

	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	int tam = ceil(sqrt(n)), quant = (n + tam - 1) / tam;
	vector<vector<ll>> B(quant);
	for (int i = 0; i < quant; i++) {
		for (int j = i * tam; j < min(n, (i + 1) * tam); j++) {
			B[i].push_back(A[j]);
		}
		sort(all(B[i]));
	}

	while (q--) {
		int l, r, v, p; cin >> l >> r >> v >> p; l--, r--, p--;

		int l_ = l / tam, r_ = r / tam;
		ll k = 0;

		if (l_ == r_) {
			for (int i = l; i <= r; i++) {
				k += (A[i] < v);		
			}
		} else {
			for (int i = l, lim = ((l_ + 1) * tam) - 1; i <= lim; i++) {
				k += (A[i] < v);
			}
			
			for (int i = l_ + 1; i <= r_ - 1; i++) {
				k += lower_bound(all(B[i]), v) - B[i].begin();
			}

			for (int i = (r_ * tam); i <= r; i++) {
				k += (A[i] < v);
			}
		}

		ll val_ = u * k / (r - l + 1);
		int bp = p / tam;
		int pos = lower_bound(all(B[bp]), A[p]) - B[bp].begin();
		B[bp][pos] = val_;
		sort(all(B[bp]));
		A[p] = val_;
	}

	for (ll i : A) cout << i << endl;

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

