#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n), B(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	auto da = [&](double mid) {
		vector<double> C(n);
		for (int i = 0; i < n; i++) {
			C[i] = A[i] - mid * B[i];
		}
		sort(all(C)); reverse(all(C));

		return accumulate(C.begin(), C.begin() + k, 0.0) >= 0.0;
	};

	double l = 0, r = 1e12;
	for (int i = 0; i < 100; i++) {
		double mid = (l + r) / 2.0;	

		if (!da(mid)) {
			r = mid;	
		} else {
			l = mid;	
		}
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
