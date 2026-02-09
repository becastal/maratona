#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const ll pot = 69420;
const ll mod = 1e9+9;

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<ll> base(n+1, 1), P(n+1, 0);	
	for (int i = 1; i <= n; i++) {
		base[i] = base[i-1] * pot % mod;
		P[i] = (P[i-1] * pot + S[i-1]) % mod;
	}

	auto hash = [&](int l, int r) {
        return (P[r + 1] - base[r - l + 1] * P[l] % mod + mod) % mod;
	};

	int res = 0;
	for (int l = 0, r = n-1; l <= r; ) {
		int ok = 0;
		for (int tam = 1; tam <= (r - l + 1) / 2; tam++) {
			if (hash(l, l + tam - 1) == hash(r - tam + 1, r)) {
				l += tam, r -= tam;
				res += 2;
				ok = 1;
				break;
			}
		}
		if (!ok) {
			res++;
			break;
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

