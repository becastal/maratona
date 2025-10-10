#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n; cin >> n;
	vector<array<int, 2>> A(n);
	for (auto& [a, b] : A) cin >> a >> b;

	auto da = [&](ll m) {

		ll raio = m;
		for (int i = 1; i < n; i++) {
			ll dist = abs(A[i][0] - A[i-1][0]) + abs(A[i][1] - A[i-1][1]);
			if (dist - raio <= 0) return 0;
			raio = dist - raio;
		}
		return 1;
	};

	ll l = 1, r = 1e12, res = -1;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (da(m)) {
			l = m + 1;
			res = m;
		} else {
			r = m - 1;
		}
	}
	cout << res << endl;
	
	return 0;
}
