#include <bits/stdc++.h>
// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 2010;
const int MOD = 1e8;

struct mint {
	unsigned int v;
	bool passou;

	mint() : v(0), passou(0) {};
	mint(int a) : v(a), passou(0) {};
	mint& operator +=(const mint& a) { 
		v += a.v, passou |= a.passou; 
		if (v >= MOD) v -= MOD, passou = 1; 
		return *this; 
	}
	friend mint operator +(mint a, mint b) { return a += b; }
};
mint F[4][MAX+3][MAX+3];

struct bit2d {
	int n = MAX, m = MAX;
	bit2d() {
		memset(F, 0, sizeof(F));
	}

	void update(int k, int x, int y, mint v) {
		for (int i = x+1; i <= n; i+=i&-i) {
			for (int j = y+1; j <= m; j+=j&-j) {
				F[k][i][j] += v;
			}
		}
	};

	mint query(int k, int x, int y) {
		mint res = 0;
		for (int i = x+1; i; i-=i&-i) {
			for (int j = y+1; j; j-=j&-j) {
				res += F[k][i][j];
			}
		}
		return res;
	};
};

int solve() {
	int n; cin >> n;
	vector<int> A(n), B(n);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	vector<int> A_(A), B_(B);
	sort(all(A_));
	A_.erase(unique(all(A_)), A_.end());
	for (int& i : A) i = lower_bound(all(A_), i) - A_.begin();
	sort(all(B_));
	B_.erase(unique(all(B_)), B_.end());
	for (int& i : B) i = lower_bound(all(B_), i) - B_.begin();

//  O(n^4);
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			for (int ii = j + 1; ii < n; ii++) {
//				for (int jj = ii + 1; jj < n; jj++) {
//					res += 
//						A[i] < A[j] and A[j] < A[ii] and A[ii] < A[jj] and
//						B[i] < B[j] and B[j] < B[ii] and B[ii] < B[jj];
//				}
//			}
//		}
//	}

//	vector dp(n, vector<int>(4, 0));
//	for (int i = 0; i < n; i++) dp[i][0] = 1;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < i; j++) if (A[i] > A[j] and B[i] > B[j]) {
//			for (int k = 1; k < 4; k++) {
//				dp[i][k] += dp[j][k-1];
//			}
//		}
//	}
//
//	int res = 0;
//	for (int i = 0; i < n; i++) {
//		res += dp[i][3];
//	}
//	cout << res << endl;


//	agora O(nlog^2n) com uma bit2d pra poder fazer queries dos que sao A[j] e B[j] < que eu mesmo tempo;
	bit2d bit;

	mint res = 0;
	for (int i = 0; i < n; i++) {
		mint q0 = (A[i] and B[i]) ? bit.query(0, A[i]-1, B[i]-1) : mint(0);
		mint q1 = (A[i] and B[i]) ? bit.query(1, A[i]-1, B[i]-1) : mint(0);
		mint q2 = (A[i] and B[i]) ? bit.query(2, A[i]-1, B[i]-1) : mint(0);

		if (q2.v or q2.passou) {
			bit.update(3, A[i], B[i], q2);
			res += q2;
		}

		if (q1.v or q1.passou) {
			bit.update(2, A[i], B[i], q1);
		}

		if (q0.v or q0.passou) {
			bit.update(1, A[i], B[i], q0);
		}

		bit.update(0, A[i], B[i], mint(1));
	}

	if (res.passou) cout << setw(8) << setfill('0') << res.v << endl;
	else cout << res.v << endl;

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

