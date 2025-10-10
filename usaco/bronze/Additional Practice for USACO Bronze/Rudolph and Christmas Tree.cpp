#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; double d, h; cin >> n >> d >> h;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	double res = d * h / 2.0;
	for (int i = 0; i < n-1; i++) {
		if (A[i+1] >= A[i] + h) res += d * h / 2.0;
		else {
			double d_ = double(d) * (A[i] + h - A[i+1]) / h;
			double h_ = A[i+1] - A[i];
			res += (d_ + d) / 2.0 * h_;
		}
	}
	cout << fixed << setprecision(13) << res << endl;

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

