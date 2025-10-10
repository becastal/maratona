#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef __int128_t ll;
using namespace std;

std::ostream& operator<<(std::ostream& os, __int128_t v) {
    if (!os.good()) return os;
    if (v == 0) { os.put('0'); return os; }
    bool neg = v < 0;
    __uint128_t u = neg ? __uint128_t(-v) : __uint128_t(v);
    char buf[40]; int i = 0;
    while (u) { buf[i++] = char('0' + (u % 10)); u /= 10; }
    if (neg) os.put('-');          // your outputs are nonnegative, but keep for safety
    while (i--) os.put(buf[i]);
    return os;
}

std::istream& operator>>(std::istream& is, __int128_t& v) {
    if (!is.good()) return is;
    v = 0;
    // skip leading whitespace
    int c = is.peek();
    while (std::isspace(c)) { is.get(); c = is.peek(); }

    bool neg = false;
    if (c == '+' || c == '-') { neg = (c == '-'); is.get(); }

    bool any = false;
    while (true) {
        c = is.peek();
        if (c < '0' || c > '9') break;
        any = true;
        v = v * 10 + (__int128_t)(c - '0'); // input < 1e18, so this won't overflow
        is.get();
    }
    if (!any) { is.setstate(std::ios::failbit); }
    if (neg) v = -v;
    return is;
}

int solve() {
	int n; cin >> n;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;
	sort(all(A));

    if (n == 1) {
        if (A[0] == 1) cout << "*" << endl;
        else cout << A[0] << " 1" << endl;
        return 0;
    }

	if (A[0] != 1) return cout << A[n-1] << " 1" << endl, 0;

	if (n == 2) {
		ll s = ll(sqrtl(A[1]));
		if (A[1] == s * s) cout << A[1] << ' ' << s << endl;
		else cout << A[1] * A[1] << ' '	<< A[1] * A[1] << endl;
		return 0;
	}

	for (int i = 0; i < n-1; i++) {
		if (A[n-1] % A[i]) {
			ll a = A[n-1] * A[1];
			return cout << a << ' ' << a << endl, 0;
		}
	}

	int torre = 1;
	for (int i = 1; i < n; i++) {
		torre &= (A[i] == A[i-1] * A[1]);
	}
	if (torre) return cout << A[1] * A[n-1] << ' ' <<  A[1] * A[n-1] << endl, 0;

	for (int l = 0, r = n-1; l <= r; l++, r--) {
		if (A[r] * A[l] != A[n-1]) {
			return cout << A[n-1] << ' ' << A[n-1] / (A[r] * A[l] > A[n-1] ? A[r] : A[l]) << endl, 0;
		}
	}
	cout << A[n-1] << ' ' << ll(sqrtl(A[n-1])) << endl;

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

