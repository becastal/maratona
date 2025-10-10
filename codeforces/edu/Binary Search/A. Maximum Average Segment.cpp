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
	int n, d; cin >> n >> d;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	
	auto da = [&](double mid) -> pair<int, pair<int, int>> {
		vector<double> P(n + 1, 0.0);
		for (int i = 1; i <= n; i++) {
			P[i] = P[i-1] + (A[i-1] - mid);
		}

		double mn = 0.0;
		int posmn = 0;
		for (int i = d; i <= n; i++) {
			if (P[i-d] < mn) {
				mn = P[i-d];
				posmn = i-d;
			}

			if (P[i] - mn >= 0) return {1, {posmn+1, i}};
		}
		return {0, {-1, -1}};	
	};

	pair<int, int> res(-1, -1);
	double l = *min_element(A.begin(), A.end()), r = *max_element(A.begin(), A.end());
	for (int i = 0; i < 1000; i++) {
		double m = (l + r) / 2.0;

		auto [ok, res_] = da(m);
		if (ok) {
			l = m;
			res = res_;
		} else {
			r = m;
		}
	}
	cout << res.f << ' ' << res.s << endl;


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
