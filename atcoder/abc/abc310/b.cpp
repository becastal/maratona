#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<int> P(n);
	vector<set<int>> F(n);

	for (int i = 0, nn; i < n; i++) {
		cin >> P[i] >> nn;
		for (int j = 0, x; j < nn; j++) {
			cin >> x;
			F[i].insert(x);
		}
	}

	auto contem = [](set<int> a, set<int> b) {
		for (int i : a) {
			if (!b.count(i)) return 0;
		}
		return 1;
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (P[i] >= P[j] and contem(F[i], F[j]) and (P[i] > P[j] or F[j].size() > F[i].size())) {
				return cout << "Yes" << endl, 0;
			}
		}
	}
	cout << "No" << endl;

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

