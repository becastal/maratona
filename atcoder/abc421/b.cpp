#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	ll a, b; cin >> a >> b;

	auto rev = [](ll a) {
		string S = "";
		while (a) {
			S.push_back('0' + (a % 10));
			a /= 10;
		}
		return stoll(S);
	};

	for (int i = 0; i < 9; i++) {
		ll c = a + b;
		c = rev(c);
		a = b, b = c;
	}
	cout << a << endl;

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

