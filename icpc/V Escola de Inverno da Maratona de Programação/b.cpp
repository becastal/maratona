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

int f(int x) {
	if (x == 1) return 1;
	return x * f(x-1);
}

int solve() {
	int n, t; cin >> n >> t;

	vector<int> B(n);
	iota(B.begin(), B.end(), 1);

	int res = 0;
	do {
		int agr = 0;
		for (int i = 0; i < n; i++) {
			agr += abs((i + 1) - B[i]);
		}
		res += agr <= t;
	} while (next_permutation(B.begin(), B.end()));
	dbg(res * f(n));

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
