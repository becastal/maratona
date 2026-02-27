#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	int g = accumulate(all(A), 0LL, [&](int a, int b) {
		return gcd(a, b);
	});

	int a = 0;
	for (int& i : A) {
		i /= g;
		if (__builtin_popcountll(i) > 1) return cout << -1 << endl, 0;
		a += (1 << __lg(i));
	}

	int b = 1;
	while (b < a) {
		b <<= 1;
	}
//	cout << "a: " << a << endl;
//	cout << "b: " << b << endl;
	cout << __builtin_popcountll(b - a) << endl;


	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
