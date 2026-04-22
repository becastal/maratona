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

	

	int res = 0, i = 0, j = 0;
	for (; i < n and j < m; ) {
		if (A[i] == B[j]) {
			i++, j++;	
		} else if (A[i] == 'A' and B[j] != 'A') {
			res++, i++;	
		} else if (A[i] != 'A' and B[j] == 'A') {
			res++, j++;	
		} else {
			return cout << -1 << endl, 0;
		}
	}

	while (i < n) {
		if (A[i++] != 'A') return cout << -1 << endl, 0;
		else res++;
	}

	while (j < m) {
		if (B[j++] != 'A') return cout << -1 << endl, 0;
		else res++;
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

