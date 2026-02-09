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

	vector<int> P(n), F(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and S[i] != S[j]) j = P[j-1];
		F[P[i] = (j += S[i] == S[j])]++;
	}

	for (int i = n-1; i; i--) {
		F[P[i-1]] += F[i];	
	}

	for (int i = 0; i < n; i++) {
		F[i]++;
	}

	for (int x = P[n-1]; x; x = P[x-1]) {
		if (F[x] >= 3) return cout << S.substr(0, x) << endl, 0;
	}
	cout << "Just a legend" << endl;

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

