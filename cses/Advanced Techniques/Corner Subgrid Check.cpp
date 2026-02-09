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
 
int solve() {
	int n, k; cin >> n >> k;
	int m = (n + 64 - 1) / 64;

	vector<string> B(n);
	for (auto& i : B) {
		cin >> i;
	}
	vector<vector<ll>> A(n, vector<ll>(m));
 
 	vector<int> R(k);
 	for (int c = 0; c < k; c++) {
		for (int i = 0; i < n; i++) {
			fill(all(A[i]), 0);
			for (int j = 0; j < n; j++) {
				if (B[i][j] == ('A' + c)) {
					A[i][j >> 6] |= (1LL << (j & 63));
				}
			}
		}
	 
		ll res = 0;
		for (int i = 0; i < n and !res; i++) {
			for (int j = i + 1; j < n and !res; j++) {
				ll agr = 0;
				for (int ii = 0; ii < m; ii++) {
					agr += __builtin_popcountll(A[i][ii] & A[j][ii]);
				}
				res += (agr * (agr - 1)) / 2;
			}
		}
		R[c] = !!res;
	}
	for (int i = 0; i < k; i++) {
		cout << (R[i] ? "YES\n" : "NO\n");
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
