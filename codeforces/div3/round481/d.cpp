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
	vector<int> A(n);
	for (int& i : A) cin >> i;
	if (n <= 2) return cout << 0 << endl, 0;

	int res = INF;
	for (int ii = -1; ii <= 1; ii++) {
		for (int jj = -1; jj <= 1; jj++) {
			int d = (A[1] + jj) - (A[0] + ii);

			int agr = !!ii + !!jj;
			for (int i = 2; i < n and agr != INF; i++) {
				int diff = A[i] - ((A[0] + ii) + d * i);
				if (abs(diff) > 1) agr = INF;
				else agr += !!diff;
			}
			res = min(res, agr);
		}
	}
	cout << (res == INF ? -1 : res) << endl;

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
