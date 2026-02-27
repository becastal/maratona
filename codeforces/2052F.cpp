#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;

	vector<string> A(2);
	cin >> A[0] >> A[1];

	vector<array<int, 2>> P;
	for (int i = 0; i < n; i++) {
		if (A[0][i] != A[1][i]) {
			P.push_back({i, A[0][i] == '#'});	
		} else if (A[0][i] == '#') {
			if ((int)P.size() & 1) {
				return cout << "None" << endl, 0;
			}
		}
	}
	if ((int)P.size() & 1) {
		return cout << "None" << endl, 0;
	}

	for (int i = 0; i < (int)P.size(); i += 2) {
		auto [pi, ti] = P[i];
		auto [pj, tj] = P[i + 1];

		if (((pj - pi - 1) & 1) != ((ti == tj) ^ 1)) return cout << "None" << endl, 0;

		for (int j = pi; j <= pj; j++) {
			A[0][j] = A[1][j] = '#';
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (A[0][i] == '.' and
			A[1][i+1] == '.' and
			A[0][i] == '.' and
			A[1][i+1] == '.') return cout << "Multiple" << endl, 0;
	}
	cout << "Unique" << endl;

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

