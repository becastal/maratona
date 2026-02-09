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
	int n; cin >> n;
	int m = (n + 64 - 1) / 64;
 
	vector<vector<ll>> A(n, vector<ll>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			if (c == '1') {
				A[i][j >> 6] |= (1LL << (j & 63));
			}
		}
	}
 
	ll res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll agr = 0;
			for (int k = 0; k < m; k++) {
				agr += __builtin_popcountll(A[i][k] & A[j][k]);
			}
			res += (agr * (agr - 1)) / 2;
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
