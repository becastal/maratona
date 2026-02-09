#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<int> C(26, 0);
	for (char c : S) {
		C[c - 'a']++;
	}

	ll res = 1;
	for (int i = 0; i < 26; i++) {
		res += 1LL * C[i] * (C[i] + 1) / 2;
	//	if (C[i]) {
	//		cout << char('a' + i) << ' ' << C[i] * (C[i] + 1) / 2 << endl;
	//	}
	}

	for (int l = 0, r; l < n; l = r) {
		r = l + 1;
		while (r < n and S[r] == S[l]) r++;

		ll tam = r - l;
		res -= tam * (tam - 1) / 2;
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

