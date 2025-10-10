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
array<ll, 3> dp[20][2][2]; // jeitos, cont, soma
string S;

array<ll, 3> f(int pos, int tight, int zeroE) {
	if (pos == S.size()) {
		if (zeroE) return {0, 0, 0};
		return {1, 0, 0};
	}
	auto& res = dp[pos][tight][zeroE];
	if (res[0] != -1) return res;

	res = {0, 0, 0};
	int teto = tight ? S[pos] - '0' : 9;

	for (int i = 0; i <= teto; i++) {
		int tight_ = tight and (i == teto), zeroE_ = zeroE and (i == 0);

		array<ll, 3> a = f(pos + 1, tight_, zeroE_);

		array<ll, 3> b = a;
		if (!zeroE_) {
			b[1] += a[0];	
			b[2] += a[0] * i;	
		}

		res[0] += b[0];
		res[1] += b[1];
		res[2] += b[2];
	}
	return res;
}

pair<ll, ll> calc() {

	ll cont = 0, soma = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 2; j++) {
			for (int ii = 0; ii < 2; ii++) {
				dp[i][j][ii] = {-1, -1, -1};
			}
		}
	}

	array<ll, 3> c = f(0, 1, 1);
	return pair<ll, ll>(c[1], c[2]);
}


int solve() {
	// achar o numero que chega no kesimo digto bb + dp digito
	// depois dp dig com soma e ja era.

	ll k; cin >> k;

	ll k_ = k;
	ll d = 1, cont = 9, i = 1;
	while (k_ > d * cont) {
		k_ -= d * cont;
		d++;
		cont *= 10, i *= 10;
	}
	ll m = i + (k_ - 1) / d;

	S = to_string(m);
	auto [res_cont, res_soma] = calc();

	for (ll i = k + 1; i <= res_cont; i++) res_soma -= kesimo(i);
	cout << res_soma << endl;

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

