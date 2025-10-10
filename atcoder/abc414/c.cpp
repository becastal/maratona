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
	ll a, n; cin >> a >> n;

	vector<ll> pot = {1};
	for (int i = 0; i < 15; i++) pot.push_back(pot.back() * 10);

	auto sz = [](ll x) {
		int res = 1;
		while (x) {
			res++;
			x /= 10;
		}
		return res;
	};
	auto pal = [](string a) {
		for (int l = 0, r = (int)a.size()-1; l <= r; l++, r--) {
			if (a[l] != a[r]) return 0;
		}
		return 1;
	};
	auto palA = [&](ll x) {
		string A = "";
		while (x) {
			A.push_back('0' + (x % a));
			x /= a;
		}
		reverse(all(A));

		for (int l = 0, r = (int)A.size()-1; l <= r; l++, r--) {
			if (A[l] != A[r]) return 0;
		}
		return 1;
	};

	vector<ll> P;
	function<void(int)> f = [&](int t) {
		int m = (t + 1) / 2;
		
		ll l = pot[m-1], r = pot[m];
		for (ll i = l; i < r; i++) {
			string a = to_string(i), b = a;
			if (t & 1) b.pop_back();

			reverse(all(b));
			if (pal(a + b)) P.push_back(stoll(a + b));
		}
	};
	for (int i = 1; i < sz(n); i++) {
		f(i);
	}

	ll res = 0;
	for (ll i : P) {
		if (i > n or !palA(i)) continue;
		res += i;
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
