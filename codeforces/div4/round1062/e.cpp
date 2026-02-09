#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k, x; cin >> n >> k >> x;
	vector<int> A(n);

	for (int& i : A) cin >> i;
	sort(all(A));

	auto da = [&](int m) -> pair<int, vector<int>> {
		vector<array<int, 2>> E;
		E.reserve(2 * n);
		if (m) for (int i : A) {
			E.push_back({max(0, i - (m - 1)), 0});
			E.push_back({min(x, i + (m - 1)) + 1, 1});
		}
		sort(all(E));

		vector<int> R;
		int agr = 0, ult = 0;
		for (auto [p, tp] : E) {
			if (!agr) {
				for (int i = ult; i < p and R.size() < k; i++) {
					R.push_back(i);
				}
			}
			agr += (tp ? -1 : +1);
			ult = p;
		}

		if (!agr and ult <= x) {
			for (int i = ult; i <= x and R.size() < k; i++) {
				R.push_back(i);
			}
		}

		return {R.size() == k, R};
	};

	vector<int> R(k);
	int l = 0, r = x;
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		auto [ok, P] = da(m);
		if (ok) {
			l = m + 1;
			R = P;
		} else {
			r = m - 1;
		}
	}

	for (int i = 0; i < k; i++) {
		cout << R[i] << " \n"[i==k-1];
	}

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
