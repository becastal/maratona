#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

struct KMPaut {
    int m, k;
    vector<int> p;
    vector<vector<int>> aut;

    KMPaut(const vector<int>& s, int k_) : m((int)s.size()), k(k_), p(pi(s)), aut(m+1, vector<int>(k, 0)) {
        for (int c = 0; c < k; c++) aut[0][c] = (s[0] == c ? 1 : 0);

        for (int i = 1; i < m; i++) {
            for (int c = 0; c < k; c++) {
                aut[i][c] = (s[i] == c) ? (i + 1) : aut[p[i-1]][c];
            }
        }

        for (int c = 0; c < k; c++) aut[m][c] = m;
    }
};

template <typename T>
struct Mat {
	int n;
	vector<vector<T>> A;

	Mat(int n_, int id = 0) : n(n_), A(n, vector<T>(n, 0)) {
		if (id) for (int i = 0; i < n; i++) {
			A[i][i] = 1;
		}
	}

	Mat operator * (const Mat& M) {
		Mat R(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					R.A[i][j] += A[i][k] * M.A[k][j];
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
	int n; cin >> n;

	string Alfa, S; cin >> Alfa >> S;
	int m = (int)S.size(), k = (int)Alfa.size();

	vector<int> A(m);
	for (int i = 0; i < m; i++) {
		A[i] = lower_bound(all(Alfa), S[i]) - Alfa.begin();
	}

	KMPaut aut(A, k);
	for (int c = 0; c < k; c++) {
		aut.aut[m][c] = m;
	}

	Mat<uint32_t> M(m + 1);

	for (int i = 0; i <= m; i++) {
		for (int c = 0; c < k; c++) {
			M.A[i][aut.aut[i][c]]++;
		}
	}

	M ^= n;

	//for (int i = 0; i <= m; i++) {
	//	for (int j = 0; j <= m; j++) {
	//		cout << M.A[i][j] << " \n"[j==m];
	//	}
	//}
	// acho:

	uint32_t res = 0;
	for (int i = 0; i < m; i++) {
		res += M.A[0][i];
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
    
    return(0);
}

