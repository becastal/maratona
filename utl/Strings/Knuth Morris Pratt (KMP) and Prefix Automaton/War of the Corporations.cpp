#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string A, B; cin >> A >> B;
	int n = (int)A.size(), m = (int)B.size();

	vector<int> P(m);
	for (int i = 1, j = 0; i < m; i++) {
		while (j and B[j] != B[i]) j = P[j-1];
		P[i] = (j += B[j] == B[i]);
	}

	vector<int> O;
	for (int i = 0, j = 0; i < n; i++) {
		while (j and B[j] != A[i]) j = P[j-1];	
		j += (B[j] == A[i]);
		if (j == m) O.push_back(i);
	}

	int res = 0, ult = LLONG_MIN;
	for (int r : O) {
		int l = r - m + 1;
		if (ult < l) {
			res++;
			ult = r;
		}
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

