#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, l, r, res = 0; cin >> n >> l >> r;
	string S; cin >> S;

	vector<int> C(26);
	for (int i = 0; i < n; i++) {
		if (i - l >= 0) {
			C[S[i - l] - 'a']++;
		}
		if (i - r - 1 >= 0) {
			C[S[i - r - 1] - 'a']--;
		}
		res += C[S[i] - 'a'];
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

