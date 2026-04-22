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
	vector<int> P(n), P_(n);
	for (int i = 0; i < n; i++) {
		cin >> P[i];
		P_[--P[i]] = i;
	}

	vector<array<int, 2>> Res;
	for (int i = 0; i < n; i++) {
		if (P[i] != i) {
			int j = P_[i], pi = P[i];
			Res.push_back({i, j});
			P[j] = pi;
			P_[pi] = j;
			P[i] = P_[i] = i;
		}

	}

	cout << (int)Res.size() << endl;
	for (int i = 0; i < (int)Res.size(); i++) {
		cout << Res[i][0] + 1 << " " << Res[i][1] + 1 << endl;
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

