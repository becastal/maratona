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
	ll px, py, qx, qy;
	cin >> px >> py >> qx >> qy;

	vector<long double> A(n);
	for (long double& i : A) cin >> i;

	A.push_back(sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy)));
	cout <<  (2.0 * *max_element(A.begin(), A.end()) <= accumulate(A.begin(), A.end(), 0.0) ? "YES" : "NO") << endl;

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
