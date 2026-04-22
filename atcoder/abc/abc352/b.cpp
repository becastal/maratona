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

	for (int i = 0, j = 0; i < (int)B.size() and j < (int)A.size(); i++) {
		if (A[j] == B[i]) {
			cout << i + 1 << ' ';	
			j++;
		}
	}
	cout << endl;

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

