#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 1e9+7;
int exp(int a, int e) {
	if (!e) return 1;
	int res = (e & 1 ? a : 1);
	return res * exp(a * a % mod, e / 2) % mod;
}

int solve() {
	int n; cin >> n;

	int N = 2*n;
	vector<int> Fat(N+1, 1);
	for (int i = 2; i <= N; i++) {
		Fat[i] = Fat[i-1] * i % mod;
	}

	vector<int> Invfat(N+1, 1);
	Invfat[N] = exp(Fat[N], mod - 2);
	for (int i = N-1; i >= 1; i--) {
		Invfat[i] = (i+1) * Invfat[i+1] % mod; 
	}

	auto Comb = [&](int a, int b) {
		if (a < b) return 0LL;
		return Fat[a] * Invfat[b] % mod * Invfat[a-b] % mod;
	};

	int res = 1, estados = 1;
	for (int i = 1; i <= 2*n; i++) {
		estados = (2 * estados % mod - 2 * Comb(i - 1, n) % mod + mod) % mod;
		res = (res + estados) % mod;
	}
	cout << res << endl;

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

