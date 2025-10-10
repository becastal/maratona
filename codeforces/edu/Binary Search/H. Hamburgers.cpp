#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	string s; cin >> s;
	
	vector<ll> A(3, 0);
	for (char c : s) {
		A[c == 'B' ? 0 : (c == 'S' ? 1 : 2)]++;
	}

	vector<ll> Q(3, 0), P(3, 0);
	for (ll& i : Q) cin >> i;
	for (ll& i : P) cin >> i;
	ll tenho; cin >> tenho;


	auto da = [&](ll mid) {
		ll preco = 0;
		for (int i = 0; i < 3; i++) {
			ll falta = max(0LL, (A[i] * mid) - Q[i]);
			preco += falta * P[i];
		}
		return preco <= tenho;
	};

	ll l = 0, r = (ll)1e15+10, res = r;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (da(mid)) {
			l = mid+1;
			res = mid;
		} else {
			r = mid-1;
		}
	}
	cout << res << endl;

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
