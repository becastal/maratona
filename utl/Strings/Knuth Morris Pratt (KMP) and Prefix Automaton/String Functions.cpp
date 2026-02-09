#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

abaabca
0 0 1 2 0 0 1
0 0 1 1 2 0 1

*/

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<int> P(n), Z(n);
	for (int i = 1, j=  0; i < n; i++) {
		while (j and S[i] != S[j]) j = P[j-1];
		P[i] = (j += S[i] == S[j]);
	}

	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
		while (i + Z[i] < n and S[Z[i]] == S[i + Z[i]]) Z[i]++;
		if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
	}

	for (int i = 0; i < n; i++) {
		cout << Z[i] << " \n"[i==n-1];
	}
	for (int i = 0; i < n; i++) {
		cout << P[i] << " \n"[i==n-1];
	}

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

