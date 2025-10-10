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
	int n, m; cin >> n >> m;
	vector<ll> A(n), B(m);
	
	for (ll& i : A) cin >> i;
	for (ll& i : B) cin >> i;
	sort(all(A));
	sort(all(B));

	vector<ll> Pl(n+1, 0), Pr(n+1, 0);
	for (int i = 1; i <= n; i++) {
		Pl[i] = Pl[i-1] + abs(A[i-1] - B[m-i]);
		Pr[i] = Pr[i-1] + abs(A[n-i] - B[i-1]);
	}

	ll res = 0;
	for (int i = 0; i <= n; i++) {
		res = max(res, Pl[i] + Pr[n-i]);
	}
	cout << res << endl;

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
