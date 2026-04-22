#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, p cin >> n >> p;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<vector<int>> S(n, vector<int>(p));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cin >> S[i][j];
		}
	}

	vector<int> O(n);
	iota(all(O), 0);

	sort(all(O));

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

