#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	if (n == 1) return cout << 1 << endl, 0;
	vector<int> R(n, 0);
	priority_queue<array<int, 3>> P;
	R[0] = 1, R[n-1] = 2;

	P.push({(n-1)/2, -1, n-2});
	for (int i = 3; i <= n; i++) {
		auto [d, p, tam] = P.top(); P.pop();
		p = -p;

		if (tam & 1) {
			int m = p + tam / 2;
			R[m] = i;

			int l = tam / 2;
			int r = tam / 2;
			if (l > 0) P.push({(l + 1) / 2, -p, l});
			if (r > 0) P.push({(r + 1) / 2, -(m + 1), r});
		} else {
			int m = p + tam / 2 - 1;
			R[m] = i;

			int l = tam / 2 - 1;
			int r = tam / 2;
			if (l > 0) P.push({(l + 1) / 2, -p, l});
			if (r > 0) P.push({(r + 1) / 2, -(m + 1), r});
		}
	}
	for (int i : R) cout << i << ' '; cout << endl;

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
