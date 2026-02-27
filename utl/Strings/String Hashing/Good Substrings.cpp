#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int _1e99 = 1e9+9;
const int _1e97 = 1e9+7;
const int p = 69429;

int solve() {
	string S, T; cin >> S >> T;
	int k, n = (int)S.size(); cin >> k;

	vector<int> P(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] + (T[S[i-1] - 'a'] == '0');
	}

	unordered_set<int> Set;
	auto H = [&](int a, int b) {
		return a << 30 | b;
	};

	for (int l = 0; l < n; l++) {
		int hash1 = 0, hash2 = 0;
		for (int r = l; r < n; r++) {
			hash1 = (hash1 * p + S[r]) % _1e99;
			hash2 = (hash2 * p + S[r]) % _1e97;

			if (P[r+1] - P[l] <= k) {
				//cout << "(" << l << ", " << r << ")\n";
				Set.insert(H(hash1, hash2));	
			}
		}
	}
	cout << (int)Set.size() << endl;

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

