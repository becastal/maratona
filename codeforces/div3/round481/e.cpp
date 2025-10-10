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
	int n, w; cin >> n >> w;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	for (int i = 1; i < n; i++) {
		A[i] += A[i-1];
	}

	ll l = max(0LL, -*min_element(A.begin(), A.end())), r = w - max(0LL, *max_element(A.begin(), A.end()));
	cout << max(0LL, r - l + 1) << endl;

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
