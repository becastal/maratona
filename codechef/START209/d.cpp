#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	111
	11
	sao os que nao tem o que fazer
*/

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	int m = 0;
	vector<int> C(n+1, 0);
	for (int l = 0, r = 0; l < n; l = r) {
		r = l + 1;
		if (S[l] == '0') continue;
		while (S[r] == '1') r++;
		C[(r - l)]++;
		m++;
	}

	if (m == 1 and (C[2] == 1 or C[3] == 1)) return cout << "NO" << endl, 0;
	cout << "YES" << endl;

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

