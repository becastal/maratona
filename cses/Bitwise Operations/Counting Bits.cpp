#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll n; cin >> n;

	ll res = 0;
	for (int i = 0; i < 60; i++) {
		ll a = (n + 1) / (1LL << (i + 1)), b = (n + 1) % (1LL << (i + 1));

		ll add = a * (1LL << i);
		if (b > (1LL << i)) add += b - (1LL << i);
		res += add;
	}
	cout << res << endl;
//
//	int res_ = 0;
//	for (int i = 0; i <= n; i++) {
//		cout << bitset<10>(i).to_string() << endl;
//		res_ += __builtin_popcount(i);
//	}
//	cout << res_ << endl;

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

