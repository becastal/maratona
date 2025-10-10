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
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<int> pre(n+1, 0);
	for (int i = 2; i <= n; i++) {
		pre[i] = pre[i-1] + max(0, A[i-2] - A[i-1]);
	}
	for (int i = 1; i <= n; i++) {
		pre[i] += pre[i-1];
	}

	while (q--) {
		int l, r; cin >> l >> r; 
		cout << pre[r] - pre[l] << endl;
	}

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
