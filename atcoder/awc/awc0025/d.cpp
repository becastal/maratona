#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, s, q; cin >> n >> s >> q; s--;

	vector<int> X(n);
	for (int& i : X) {
		cin >> i;
	}

	vector<int> O(n);
	iota(all(O), 0);
	sort(all(O), [&](int a, int b) {
		return X[a] < X[b];
	});

	auto Dist = [&](int a, int b) {
		return abs(X[a] - X[b]);
	};
	
	const int LG = 63;
	vector<vector<int>> P(LG + 1, vector<int>(n));
	P[0][O[0]] = O[1];
	P[0][O[n-1]] = O[n-2];
	for (int p = 1; p < n - 1; p++) {
		int i = O[p-1], j = O[p], k = O[p+1];
		
		if (Dist(i, j) == Dist(j, k)) {
			P[0][j] = min(i, k);
		} else if (Dist(i, j) < Dist(j, k)) {
			P[0][j] = i;
		} else {
			P[0][j] = k;
		}
	}

	for (int i = 1; i <= LG; i++) {
		for (int j = 0; j < n; j++) {
			P[i][j] = P[i-1][P[i-1][j]];
		}
	}

	for (int i = LG; i >= 0; i--) if (q >> i & 1) {
		s = P[i][s];
	}
	cout << s + 1 << endl;

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

