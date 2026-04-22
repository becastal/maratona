#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, p = 1; cin >> n;
	vector<int> Res(3 * n);

	for (int j = 0; j < 3 * n; j += 3) {
		Res[j] = p++;
	}

	for (int j = 0; j < 3 * n; j++) if (!Res[j]) {
		Res[j] = p++;
	}

	for (int i = 0; i < 3 * n; i++) {
		cout << Res[i] << " \n"[i == 3 * n - 1];
	}

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

