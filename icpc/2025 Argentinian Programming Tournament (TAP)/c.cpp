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
	for (int& i : A) cin >> i, i--;

	map<int, ll> F;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += F[(A[i] + i) % n]++;
	}
	cout << 1LL * n + 2LL * res << endl;

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

