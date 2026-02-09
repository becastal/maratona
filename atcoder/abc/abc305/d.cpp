#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<ll> P(n);
	P[0] = 0;
	for (int i = 1; i < n; i++) {
		P[i] = P[i-1];
		if (i % 2 == 0) {
			P[i] += A[i] - A[i-1];
		}
	}

	auto pref = [&](int x) {
		int i = upper_bound(all(A), x) - A.begin() - 1;
		if (i < 0) return 0LL;
		return P[i] + (i & 1 ? x - A[i] : 0);
	};

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << pref(b) - pref(a) << endl;
	}

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

