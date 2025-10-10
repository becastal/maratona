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
	int borda = -1;
	ll ruim = -LINF, falta = 0;
	for (int l = 0, r = 0; l < n; l = r) {
		r = l+1;
		if (s[l] == '0') {
			zeros.push_back(l++);
			continue;
		}
		while (r < n and s[r] == '1') {
			r++;
		}

		ll pref = 0, agr = 0;
		for (int i = l; i < r; i++) {
			agr += a[i];
			pref = max(pref, agr);
		}

		agr = 0;
		ll suf = 0;
		for (int i = r-1; i >= l; i--) {
			agr += a[i];
			suf = max(suf, agr);
		}

		ll ruim_ = kadane(l, r);
		if (ruim_ > ruim) {
			ruim = ruim_;
			if (l) {
				borda = l - 1;
				falta = k - pref;
			} else if (r < n) {
				borda = r;
				falta = k - suf;
			}
		}
	}

	if (ruim > k or zeros.empty()) return cout << "NO" << endl, 0;

	if (ruim == k) {
		for (int i : zeros) {
			a[i] = -LINF;
		}
	} else {
		if (borda == -1) {
			borda = zeros[0];
			falta = k;
		}

		for (int i : zeros) {
			a[i] = -LINF;
		}
		a[borda] = falta;
	}

	//assert(kadane(0, n) == k);
	cout << "YES" << endl;
	for (ll i : a) cout << i << ' ';
	cout << endl;
	return 0;
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
