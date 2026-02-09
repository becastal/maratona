#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
typedef vector<vector<double>> Ma;

Ma mul(Ma a, Ma b) {
	Ma c(2, vector<double>(2, 0.0));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return c;
}

Ma exp(Ma a, int n) {
	Ma b = {{1.0, 0.0}, {0.0, 1.0}};

	while (n) {
		if (n & 1) b = mul(b, a);
		a = mul(a, a);
		n >>= 1;
	}

	return b;
}

int solve() {
	int n; cin >> n;
	double p; cin >> p;

	Ma A = {
		{1.0 - p, p},
		{p, 1.0 - p}
	};

	Ma B = exp(A, n);
	cout << fixed << setprecision(13) << B[0][0] << endl;

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

