#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}
	vector<vector<int>> P(n + 1);
	vector<ll> S(n + 1), C(n + 1);
	
	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll& c = C[A[i]];
		ll& s = S[A[i]];
		res += c * i - s - ((1 + c) * c / 2);
		s += i;
		c++;
	}
	cout << res << endl;

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

