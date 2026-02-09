#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; ll x;
	cin >> n >> k >> x;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}
	sort(all(A));

	vector<ll> P(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] + A[i-1];
	}

	auto da = [&](int m) {
		int r = max(0, k + m - n);
		if (!r) return false;

		int l = n - m;
		return P[l + r] - P[l] >= x;
	};

	int l = 1, r = n, res = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		if (da(m)) {
			r = m - 1;	
			res = m;
		} else {
			l = m + 1;
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

