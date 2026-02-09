#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	int p = 1;
	vector<int> B(n, 1);
	for (int i = 1; i < n; i++) {
		ll d = A[i] - A[i-1];
		if (i - d >= 0) B[i] = B[i-d];
		else B[i] = ++p;
	}
	for (int i : B) cout << i << ' '; cout << endl;

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

