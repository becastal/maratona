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

void solve() {
	int n, k; cin >> n >> k;

	vector<int> A(n);
	for (int& i : A) cin >> i;
	sort(A.rbegin(), A.rend());

	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1 ^ 1) res += A[i];
		else {
			ll tira = min(k, A[i-1] - A[i]);

			k -= tira;
			res -= tira + A[i];
		}
	}

	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
