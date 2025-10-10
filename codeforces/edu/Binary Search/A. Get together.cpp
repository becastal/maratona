#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> A(n), V(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> V[i];
	}

	auto da = [&](double t) {
		double L = -1e20, R = 1e20;
		for (int i = 0; i < n; i++) {
			L = max(L, double(A[i]) - (V[i] * t));
			R = min(R, double(A[i]) + (V[i] * t));
		}

		return L <= R;
	};

	double l = 0.0, r = 1e12;
	for (int i = 0; i < 100; i++) {
		double m = (l + r) / 2;

		if (da(m)) {
			r = m;
		} else {
			l = m;
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
