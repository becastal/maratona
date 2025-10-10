#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll k, x; cin >> k >> x;

	ll a = x, b = (1LL << (k + 1)) - x;

	vector<int> R;
	while (a != b) {
		if (a <= b) {
			R.push_back(1);
			b -= a;
			a <<= 1;
		} else {
			R.push_back(2);
			a -= b;
			b <<= 1;
		}
	}

	reverse(all(R));
	cout << R.size() << endl;
	for (int i : R) cout << i << ' '; cout << endl;

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

