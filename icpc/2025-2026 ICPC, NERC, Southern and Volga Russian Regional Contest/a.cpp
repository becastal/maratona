#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<queue<int>> P(n);
	set<array<int, 2>> S;
	for (int i = 0, x; i < n; i++) {
		cin >> x; x--;
		P[x].push(i);
		S.insert({i, x});
	}

	int res = 0, p = 0;
	while (S.size()) {
		if (S.size() >= 2) {
			auto [ia, a] = *S.begin();
			auto [ib, b] = *next(S.begin());
			if (a == b) {
				S.erase(*S.begin());
				S.erase(*S.begin());
				P[a].pop();
				P[b].pop();
				res++;
				continue;
			}
		}

		while (P[p].empty()) p++;			
		int ia = P[p].front(), a = p; P[p].pop();
		S.erase({ia, a});
		res++;
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

