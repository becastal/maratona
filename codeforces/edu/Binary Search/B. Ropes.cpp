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
	int n, k; cin >> n >> k;

	vector<int> A(n);
	for (int& i : A) cin >> i;

	auto da = [&](double m) {
		double agr = 0;
		for (int i : A) {
			agr += floor(i / m);	
		}
		return agr >= k;
	};

	double l = 0, r = 1e15;
	for (int i = 0; i < 100; i++) {
		double m = (l + r) / 2.0;

		if (da(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << fixed << setprecision(8) << l << endl;

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
