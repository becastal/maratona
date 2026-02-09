#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*

	1111000011110000
	0111100001111000
	0011110000111100
	0001111000111110
	0000111100011111
	0000011110001111

*/

int solve() {
	int n, w; cin >> n >> w;
	vector<int> C(n);
	int m = 2*w;
	for (int& i : C) {
		cin >> i;
	}

	vector<ll> S(m);
	for (int i = 1; i <= n; i++) {
		S[i % m] += C[i-1];
	}

	vector<ll> P(2*m+1, 0);
	for (int i = 0; i < 2*m; i++) {
		P[i + 1] = P[i] + S[i % m];
	}

	ll res = LLONG_MAX;
	for (int i = 0; i < m; i++) {
		res = min(res, P[i + w] - P[i]);
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

