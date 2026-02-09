#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int x, n; cin >> x >> n;
	vector<int> W(n), P(n, 0);

	for (int& i : W) cin >> i;
	int q; cin >> q;
	while (q--) {
		int p; cin >> p; p--;

		x += (P[p] ? -1 : +1) * W[p];
		P[p] ^= 1;
		cout << x << endl;
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

