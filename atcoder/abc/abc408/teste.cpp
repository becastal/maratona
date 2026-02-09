#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<ll, ll> solve(ll a, ll b, ll c, ll d) {
	ll n = a / b;
	a -= n * b, c -= n * d;
	if (c > d)
		return {n + 1, 1};
	auto [p, q] = solve(d, c, b, a);
	return {p * n + q, p};
}
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		auto [p, q] = solve(a, b, c, d);
		cout << q << '\n';
	}
}
