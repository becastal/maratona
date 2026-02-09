#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, res = 0; cin >> n >> m;

	set<array<int, 2>> S;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;	

		int ok = 1;
		for (int di = 0; di < 2 and ok; di++) {
			for (int dj = 0; dj < 2 and ok; dj++) {
				ok &= !(S.count({a + di, b + dj}));
			}
		}

		if (ok) {
			for (int di = 0; di < 2; di++) {
				for (int dj = 0; dj < 2; dj++) {
					S.insert({a + di, b + dj});
				}
			}
			res++;
		}
	}
	cout << res << endl;

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

