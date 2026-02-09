#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, tam; cin >> n >> tam;
	vector<array<ll, 2>> A(n);
	for (auto& [x, y] : A) {
		cin >> x >> y;
	}
	sort(all(A));

	double l = 1, r = 1.5e9;
	while (r - l > 1e-3) {
		double mid = 0.5 * (l + r), agr = 0;

		for (int i = 0; i < n; i++) {
			double delta = sqrt(mid * mid - A[i][1] * A[i][1]);
			double a = A[i][0] - delta, b = A[i][0] + delta;
			if (a <= agr) agr = max(agr, b);
		}

		if (agr >= tam) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(13) << l << endl;

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

