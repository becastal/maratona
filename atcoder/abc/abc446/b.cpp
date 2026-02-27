#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	set<int> S;
	for (int i = 1; i <= m; i++) {
		S.insert(i);
	}

	vector<int> R(n);
	for (int i = 0, nn; i < n; i++) {
		cin >> nn;

		vector<int> A(nn);
		for (int& j : A) cin >> j;

		for (int j : A) {
			if (S.count(j)) {
				R[i] = j;
				S.erase(j);
				break;
			}
		}
	}
	for (int i : R) {
		cout << i << endl;
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

