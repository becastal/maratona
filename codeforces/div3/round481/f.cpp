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

	vector<int> A(n), res(n);

	for (int& i : A) cin >> i;

	auto A_ = A;
	sort(A_.begin(), A_.end());
	for (int i = 0; i < n; i++) {
		res[i] = lower_bound(A_.begin(), A_.end(), A[i]) - A_.begin();
	}

	for (int i = 0, u, v; i < k; i++) {
		cin >> u >> v; u--, v--;

		if (A[u] > A[v]) res[u]--;
		else if (A[v] > A[u]) res[v]--;
	}

	for (int i : res) cout << i << ' '; cout << endl;

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
