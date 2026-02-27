#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 1e7+10;
const int mod = 998244353;

int divi[MAX];
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

map<int, int> Fact(int n) {
	map<int, int> R;
	if (n == 1) return R;

	vector<int> f;
	fact(f, n);
	for (int i : f) {
		R[i]++;
	}
	return R;
}

int expo(int a, int b) {
	if (!b) return 1;
	int res = expo(a * a % mod, b / 2);
	if (b & 1) res *= a;
	return res % mod;
}

int inv(int a) {
	return expo(a, mod - 2);
}

int solve() {
	int n; cin >> n;

	vector<int> A(n);
	map<int, array<array<int, 2>, 2>> P;
	vector<map<int, int>> B(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		B[i] = Fact(A[i]);

		for (auto [a, b] : B[i]) {
			if (b > P[a][0][0]) {
				swap(P[a][0], P[a][1]);
				P[a][0][0] = b, P[a][0][1] = 1;
			} else if (b == P[a][0][0]) {
				P[a][0][1]++;
			} else if (b > P[a][1][0]) {
				P[a][1][0] = b, P[a][1][1] = 1;
			}
		}
	}

	int res = 1;
	for (auto [a, ar] : P) {
		res = res * expo(a, ar[0][0]) % mod;
	}

	vector<int> R(n);
	for (int i = 0; i < n; i++) {
		int res_ = res;
		for (auto [a, b] : B[i]) {
			if (b == P[a][0][0] and P[a][0][1] == 1) {
				res_ = res_ * inv(expo(a, P[a][0][0])) % mod;
				res_ = res_ * expo(a, P[a][1][0]) % mod;
			}
		}
		R[i] = res_;

		cout << R[i] << " \n"[i==n-1];
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	crivo(MAX-1);
	while (t--) {
		solve();
	}
    
    return(0);
}

