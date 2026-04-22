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
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	int m; cin >> m;
	vector<string> S(m);

	set<tuple<int, int, char>> Set;
	for (auto& s : S) {
		cin >> s;

		for (int j = 0; j < (int)s.size(); j++) {
			Set.emplace((int)s.size(), j, s[j]);
		}
	}

	for (auto& spine : S) {

		int ok_todos = (int)spine.size() == n;
		for (int i = 0; i < n and ok_todos; i++) {
			int ok = 0;
			if (Set.count({A[i], B[i] - 1, spine[i]})) {
				ok = 1;
			}
			//for (auto& s : S) if ((int)s.size() == A[i] and s[B[i] - 1] == spine[i]) {
			//	ok = 1;
			//	break;
			//}
			ok_todos &= ok;
		}

		cout << (ok_todos ? "Yes" : "No") << endl;
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

