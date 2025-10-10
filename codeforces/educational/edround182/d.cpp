#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 2e5+10;
ll P[MAX], F[MAX];

int solve() {
	memset(F, 0, sizeof(F)); memset(P, 0, sizeof(P));
	int n; cin >> n;
	ll y; cin >> y;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		F[i]++;
	}

	for (int i = 1; i < MAX; i++) {
		P[i] = P[i-1] + F[i];
	}
	auto query = [&](int l, int r) -> ll {
		l = max(l, 1), r = min(r, MAX-1);
		if (l > r) return 0LL;
		return P[r] - P[l-1];
	};
	auto soma_ceil = [&](int x) -> ll {
		ll res = 0;

		int t = (MAX + x - 1) / x;
		for (int r = 1; r <= t; r++) {
			res += r * query(r * x - r + 1, r * x);
		}

		return res;
	};

	ll res = LLONG_MIN;
	for (int x = 2; x < MAX; x++) {
		int t = (MAX + x - 1) / x, k = 0;
		for (int v = 1; v <= t; v++) {
			int a = F[v], b = query(x * v - x + 1, x * v);
			k += min(a, b);
		}

		res = max(res, soma_ceil(x) - (n - k) * y);
	}
	cout << res << endl;

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

