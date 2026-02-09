#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*

se so 0000 or 1111 entao eh so finding periods. mas tem que ser divisor tbm.

se nao eu bruto o a em:

|T| = a(C[0]) + b(C[1]);
e checo se todo 0 tem o mesmo hash

*/

const ll pot = 69420;
const ll mod = 1e9+9;

int solve() {
	string S, T; cin >> S >> T;
	int n = (int)S.size(), m = (int)T.size();

	int C[] = {0, 0};
	for (char c : S) {
		C[c - '0']++;
	}

	vector<ll> base(m+1, 1), P(m+1, 0);
	for (int i = 1; i <= m; i++) {
		base[i] = base[i-1] * pot % mod;
		P[i] = (P[i-1] * pot + T[i-1]) % mod;
	}
	auto query = [&](int l, int r) -> ll {
		ll h = (P[r + 1] - base[r - l + 1] * P[l] % mod + mod) % mod;
		if (h < 0) h += mod;
        return h;
	};

	if (max(C[0], C[1]) == m) {

		int res = 0;
		for (int tam = 1; tam <= m; tam++) if (m % tam == 0) {
			int ok = 1;

			ll hash = query(0, tam - 1);
			for (int i = tam; i < m and ok; i += tam) {
				ok &= hash == query(i, i + tam - 1);
			}
			res += ok;
		}
		cout << res << endl;

		return(0);
	}

	int res = 0;
	for (int a = 1; a * C[0] < m; a++) {
		if ((m - a * C[0]) % C[1]) continue;
		int b = (m - a * C[0]) / C[1];

		int ok = 1;
		ll hash0 = -1, hash1 = -1;

		for (int i = 0, p = 0; i < n and p < m and ok; i++) {
			if (S[i] == '0') {
				if (hash0 == -1) {
					hash0 = query(p, p + a - 1);
					p += a;
					continue;
				}
				ok &= hash0 == query(p, p + a - 1);	
				p += a;
			} else {
				if (hash1 == -1) {
					hash1 = query(p, p + b - 1);
					p += b;
					continue;
				}
				ok &= hash1 == query(p, p + b - 1);	
				p += b;
			}
		}
		ok &= hash0 != hash1;

		res += ok;
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

