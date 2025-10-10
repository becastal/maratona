#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    //_;
	srand(time(NULL));

	ll n, k; cin >> n >> k;

	auto query = [](ll l, ll r) {
		cout << l << ' ' << r << endl;
		string s; cin >> s;
		return s == "Yes";
	};

	function<void(ll, ll)> solve = [&](ll l, ll r) {
		l = max(1LL, l - k), r = min(n, r + k);

		if (r-l+1 <= 50) {
			ll chute = l+rand()%(r-l+1);
			if (query(chute, chute)) {
				exit(0);
			} else {
				solve(l, r);
			}
		} else {
			ll m = (l+r)/2;

			if (query(l, m)) {
				solve(l, m);
			} else {
				solve(m+1, r);
			}
		}
	};

	solve(1, n);
    
    return(0);
}
