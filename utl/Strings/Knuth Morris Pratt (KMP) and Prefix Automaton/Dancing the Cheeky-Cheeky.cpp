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

	vector<int> P(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and S[i] != S[j]) j = P[j-1];
		P[i] = j += (S[i] == S[j]);
	}
	int tam = n - P[n-1];

	for (int p = n % tam, i = 0; i < 8; i++, p = (p + 1) % tam) {
		cout << S[p];
	}
	cout << "...\n";

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

