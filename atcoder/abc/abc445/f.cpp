#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

template <typename T>
struct Mat {
	int n;
	vector<vector<T>> A; 

	Mat(int n_, int id = 0) : n(n_), A(n, vector<T>(n, LLONG_MAX)) {
		if (id) for (int i = 0; i < n; i++) {
			A[i][i] = 0;
		}
	}

	Mat operator * (const Mat& M) {
		Mat R(n);

		for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                ll aik = A[i][k];
                if (aik == LLONG_MAX) continue;
                for (int j = 0; j < n; j++) {
                    ll okj = M.A[k][j];
                    if (okj == LLONG_MAX) continue;
                    __int128 cand = ( __int128 )aik + okj;
                    if (cand < R.A[i][j]) R.A[i][j] = (ll)cand;
                }
            }
        }	

		return R;
	}

	Mat& operator *= (const Mat& M) {
		return *this = (*this) * M;
	}

	Mat operator ^ (int k) {
		Mat B(n, 1), base = (*this);
		
		while (k) {
			if (k & 1) B *= base;
			base *= base;	
			k >>= 1;
		}

		return B;
	}

	Mat& operator ^= (int k) {
		return *this = (*this) ^ k;
	}
};

int solve() {
	int n, k; cin >> n >> k;

	Mat<int> M(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> M.A[i][j];
		}
	}

	M ^= k;
	for (int i = 0; i < n; i++) {
		cout << M.A[i][i] << endl;
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
