#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S, T; cin >> S >> T;

	int j = 0;
	for (char c : S) {
		if (j < 3 and c == tolower(T[j])) {
			j++;
		}
	}
	// cout << "j: " << j << endl;

	cout << (j == 3 or (j == 2 and T.back() == 'X') ? "Yes" : "No") << endl;

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

