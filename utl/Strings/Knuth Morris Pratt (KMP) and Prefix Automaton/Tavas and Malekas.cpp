#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MOD = 1e9+7;
int solve() {
	int n, m; cin >> n >> m;
	string A; cin >> A;
	int nn = (int)A.size();

	vector<int> O(m), F(n + 1);
	for (int& i : O) {
		cin >> i; i--;
		F[i]++;
		F[min(n, i+nn)]--;
	}
	for (int i = 1; i <= n; i++) { 
		F[i] += F[i-1];
	}

	vector<int> P(nn);
	for (int i = 1, j = 0; i < nn; i++) {
		while (j and A[i] != A[j]) j = P[j-1];
		P[i] = (j += A[i] == A[j]);
	}

	vector<int> Ok(nn + 1); Ok[0] = Ok[nn] = 1;
	for (int x = P[nn-1]; x; x = P[x-1]) {
		Ok[x] = 1;
	}

	for (int l = 0, r; l < m; l = r) {
		r = l + 1;
		while (r < m and O[l] + nn >= O[r]) {
			r++;
		}
 
		for (int i = l + 1; i < r; i++) {
			int tam = (O[l] + nn) - O[i];
			//cout << "tam: " << tam << endl;
			if (!Ok[tam]) {
				//cout << "(" << l << ", " << i << ")\n";
				return cout << 0 << endl, 0;
			}
		}

		if (r != l + 1) r--;
	}

	int res = 1;
	for (int i = 0; i < n; i++) if (!F[i]) {
		res = (res * 26) % MOD;	
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

