#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 1e6 + 10;
int primo[MAX];

void crivo(int n) {
	memset(primo, 0, sizeof(primo));
	for (int i = 2; i <= n; i++) primo[i] = 1;

	for (int i = 2; i <= n; i++) if (primo[i]) {
		for (int j = i + i; j <= n; j += i) {
			primo[j] = 0;
		}
	}

	for (int i = 3; i <= n; i++) primo[i] += primo[i-1];
}

int solve() {
	int n, k; cin >> n >> k;

	vector<int> P(k);
	for (int& i : P) cin >> i;

	ll res = 0;
	for (int i = 1; i < (1 << k); i++) {
		ll p = 1;
		for (int j = 0; j < k; j++) if (i & (1 << j)) {
			p *= P[j];
		}
		res += (__builtin_popcount(i) & 1 ? +1 : -1) * (n / p);
	}
	cout << n - res - primo[n] + k - 1 << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cout << "Case " << ti << ": ";
		solve();
	}
    
    return(0);
}

