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
	int n, k; cin >> n >> k;
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	vector<ll> base(k + 1, 1);
	for (int i = 1; i <= k; i++) {
		base[i] = base[i-1] * pot % mod;
	}

	vector<int> R(n);
	if (n < k) {
		// o(n^2k);

		for (int i = 0; i < n; i++) {
			int ok = 1;
			for (int j = i + 1; j < n and ok; j++) {
				int ham = 0;
				for (int ii = 0; ii < k and ham <= 2; ii++) {
					ham += (A[i][ii] != A[j][ii]);
				}
				ok &= (ham <= 2);
			}
			R[i] = !ok;
		}
	} else {
		// o(k^2n);
		unordered_map<ll, ll> M;
		for (int i = 0; i < n; i++) {
			ll hash = 0;

			for (int j = 0; j < k; j++) {
				hash = (hash * pot % mod + A[i][j]) % mod;
			}

			int ok = 1;
			for (int j = 0; j < k and ok; j++) {
				ll hash_ = (hash - (base[k - j - 1] * A[i][j] % mod) + mod) % mod;
				if (M.count(hash_)) {
					ok = 0;
					R[i] = 1;
					R[M[hash_]] = 1;
				}
				M[hash_] = i;
			}

			for (int j = 0; j < k and ok; j++) {
				for (int ii = j + 1; ii < k and ok; ii++) {
					ll hash_ = (hash - (base[k - j - 1] * A[i][j] % mod) + mod 
									 - (base[k - ii - 1] * A[i][ii] % mod) + mod) % mod;
					if (M.count(hash_)) {
						ok = 0;
						R[i] = 1;
						R[M[hash_]] = 1;
					}
					M[hash_] = i;
				}
			}
			R[i] = !ok;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << R[i];
	}
	cout << "\n";

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

