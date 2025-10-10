#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int kesimo(ll k) {
	if (!k) return 0;

	ll d = 1, cont = 9, i = 1;
	while (k > d * cont) {
		k -= d * cont;
		d++;
		cont *= 10, i *= 10;
	}

	ll num = i + (k - 1) / d;
	return int(to_string(num)[(k - 1) % d] - '0');
}

int solve() {
	int k; cin >> k;
	ll l, r; cin >> l >> r;

	string A = "";
	for (ll i = l; i <= r; i++) {
		A.push_back('0' + kesimo(i));
	}

	ll res = 0, n = r - l + 1;
	for (int t = 1; t <= k; t++) {
		string S = "";
		for (int i = 0; i < t; i++) {
			S += A[i];
		}
		
		res = max(res, stoll(S));
		for (int i = t; i < n; i++) {
			S = S.substr(1);
			S += A[i];
			res = max(res, stoll(S));
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

