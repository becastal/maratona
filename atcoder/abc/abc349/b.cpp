#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<int> C(26, 0), F(n + 1, 0);
	for (char c : S) {
		C[c - 'a']++;
	}
	for (int i = 0; i < 26; i++) if (C[i]) {
		// cout << char('a' + i) << ": " << C[i] << endl;
		F[C[i]]++;
	}

	int ok = 1;
	for (int i = 0; i <= n and ok; i++) {
		ok &= (F[i] == 0 or F[i] == 2);
	}
	cout << (ok ? "Yes" : "No") << endl;

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

