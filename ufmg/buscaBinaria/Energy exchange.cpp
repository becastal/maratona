#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	double k; cin >> k;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	auto da = [&](double m) {
		double acima = 0.0, abaixo = 0.0;
		for (double i : A) {
			if (i > m) acima += i - m;
			else abaixo += m - i;
		}

		return (acima * (1.0 - k / 100.0) >= abaixo);
	};

	double l = 0.0, r = *max_element(all(A));
	for (int i = 0; i < 100; i++) {
		double m = (l + r) / 2.0;

		if (da(m)) {
			l = m;
		} else {
			r = m;
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
