#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

template <typename T>
struct Mat {
	int n, mod;
	vector<vector<T>> A;

	Mat(int n_, ll mod_, int id = 0) : n(n_), mod(mod_), A(n, vector<T>(n, 0)) {
		if (id) for (int i = 0; i < n; i++) {
			A[i][i] = 1;
		}
	}

	Mat operator * (const Mat& M) {
		Mat R(n, mod);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					R.A[i][j] = (R.A[i][j] + A[i][k] * M.A[k][j] % mod) % mod;
					
				}
			}
		}

		return R;
	}

	Mat& operator *= (const Mat& M) {
		return *this = (*this) * M;
	}

	Mat operator ^ (ll k) {
		Mat B(n, mod, 1), base = (*this);

		while (k) {
			if (k & 1) B *= base;
			base *= base;
			k >>= 1;
		}

		return B;
	}

	Mat& operator ^= (ll k) {
		return *this = (*this) ^ k;
	}
};


int solve() {
	ll a, x, m; cin >> a >> x >> m;

	Mat<ll> A(2, m);
	A.A[0][0] = a;
	A.A[0][1] = A.A[1][1] = 1;

	A ^= x;
	cout << A.A[0][1] << endl;

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

