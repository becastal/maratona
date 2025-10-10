#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

ll pot[20];
int solve() {
	ll n; cin >> n;

	vector<ll> R;
	for (int b = 18; b >= 1; b--) {
		if (n % (pot[b] + 1) == 0) {
			R.push_back(n / (pot[b] + 1));
		}
	}

	cout << R.size() << endl;
	for (ll i : R) cout << i << ' '; cout << endl;
	
	return(0);
}

int main()
{
    _;

	pot[0] = 1;
	for (int i = 1; i < 20; i++) {
		pot[i] = pot[i-1] * 10;
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

