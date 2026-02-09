#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	auto f = [&](int a) {
		int res = 0;
		while (a) {
			int b = a % 10;
			res += b * b;
			a /= 10;
		}
		return res;
	};

	set<int> vis;
	while (n != 1) {
		if (vis.count(n)) { 
			return cout << "No" << endl, 0;
		}
		vis.insert(n);
		n = f(n);
	}
	return cout << "Yes" << endl, 0;

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

