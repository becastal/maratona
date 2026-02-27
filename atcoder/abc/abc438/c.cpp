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

	stack<array<int, 2>> S;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (S.size() and S.top()[0] == x) {
			S.top()[1]++;
			if (S.top()[1] == 4) {
				S.pop();
			}
		} else {
			S.push({x, 1});
		}
	}

	int res = 0;
	while (S.size()) {
		res += S.top()[1];
		S.pop();
	}
	cout << res << endl;

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

