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
typedef __int128_t ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;

	vector<ll> A(n);
	for (int i = 0; i < n; i++) {
		long long a; cin >> a;
		A[i] = a;
	}
	long long l_, r_; cin >> l_ >> r_;
	ll l = l_, r = r_;

	int mid = n / 2;
	vector<ll> A1(A.begin(), A.begin() + mid),
			   A2(A.begin() + mid, A.end());

	auto calc = [](vector<ll>& A) {
		int n = (int)A.size();
		vector<ll> R(1 << n, 0);

		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) if (i & (1 << j)) {
				R[i] += A[j];
			}
		}
		return R;
	};

	int nl = (int)A1.size(), nr = (int)A2.size();
	auto L = calc(A1), R = calc(A2);

	vector<vector<ll>> B(nr + 1);
	for (int i = 0; i < (1 << nr); i++) {
		B[__builtin_popcount(i)].push_back(R[i]);
	}
	for (int i = 0; i < nr; i++) {
		sort(all(B[i]));
	}

	auto query = [](vector<ll>& A, ll l, ll r) {
		return upper_bound(all(A), r) - lower_bound(all(A), l);
	};

	long long res = 0;
	for (int i = 0; i < (1 << nl); i++) {
		int c = __builtin_popcount(i);
		if (c <= k and k - c <= nr) {
			res += query(B[k - c], l - L[i], r - L[i]);
		}
	}
	cout << res << endl;

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


