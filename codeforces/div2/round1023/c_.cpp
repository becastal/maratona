#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)1e18;
using namespace std;

int solve() {
    int n; cin >> n;
	ll k; cin >> k;
    string s; cin >> s;

    vector<ll> a(n);
    for (ll& i : a) cin >> i;

	auto kadane = [&](int l, int r) {
		ll res = a[l], agr = a[l];

		for (int i = l + 1; i < r; i++) {
			agr = max(a[i], agr + a[i]);
			res = max(res, agr);
		}
		return res;
	};

	if (kadane(0, n) == k) {
		cout << "YES" << endl;
		for (ll i : a) cout << i << ' ';
		cout << endl;
		return 0;
	}	

	vector<int> zeros;
	ll ruim = -LINF;
	for (int l = 0, r = 0; l < n; l = r) {
		r = l+1;
		if (s[l] == '0') {
			zeros.push_back(l++);
			continue;
		}
		while (r < n and s[r] == '1') {
			r++;
		}

		ruim = max(ruim, kadane(l, r));
	}

	if (ruim > k or zeros.empty()) return cout << "NO" << endl, 0;

    vector<ll> pref(n, 0), suf(n, 0);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur = max(0LL, cur + a[i]);
        pref[i] = cur;
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur = max(0LL, cur + a[i]);
        suf[i] = cur;
    }

    ll bestLR = -LINF;
    int borda = -1;
    for (int i : zeros) {
        ll L = (i > 0 ? pref[i - 1] : 0);
        ll R = (i + 1 < n ? suf[i + 1] : 0);
        if (L + R <= k && L + R > bestLR) {
            bestLR = L + R;
            borda = i;
        }
    }
    if (borda < 0) return cout << "NO" << endl, 0;
    ll falta = k - bestLR;

    for (int i : zeros) {
        a[i] = (i == borda ? falta : -LINF);
    }

    if (kadane(0, n) != k) {
        cout << "NO" << endl;
    } else {
		cout << "YES" << endl;
        for (ll x : a) cout << x << ' ';
        cout << endl;
    }

    return(0);
}

int main() {
    _;

    int t = 1; cin >> t;
    while (t--) {
        solve();
    }

    return(0);
}
