#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, l;
	double x, y;
	cin >> n >> m >> l >> x >> y; 

	vector<array<int, 3>> E(n + m);

	for (int i = 0, si, ti; i < n; i++) {
		cin >> si >> ti;
		E[i] = {si, 0, ti};
	}

	for (int i = 0, pi; i < m; i++) {
		cin >> pi;
		E[n + i] = {pi, 1, i};
	}

	sort(all(E));

	vector<double> R(m);

	double melhor = 1e18;
	for (auto [p, tp, ex] : E) {
		if (!tp) {
			melhor = min(melhor, (ex - p) / x + (l - ex) / y);
		} else {
			R[ex] = min(melhor, (l - p) / y);
		}
	}

	cout << fixed << setprecision(13);
	for (double i : R) {
		cout << i << endl;
	}

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

