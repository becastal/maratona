#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> P(n), vis(n, 0), R;
	for (int& i : P) cin >> i, i--;

//	for (int i = 0; i < n; i++) {
//		cout << i + 1 << ' ' << P[i] + 1 << endl;
//	}

	int a = -1;
	for (int u = 0; ; u = P[u]) {
		if (vis[u]) {
			a = u;
			break;
		}
		vis[u] = 1;
		R.push_back(u);
	}

	vector<int> R_;

	for (int i = 0, ok = 0; i < (int)R.size(); i++) {
		ok |= R[i] == a;
		if (ok) R_.push_back(R[i]);
	}

	cout << R_.size() << endl;
	for (int i : R_) cout << i + 1 << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

