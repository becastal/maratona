#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<ll> A(n), B(n);
	for (ll& i : A) cin >> i;
	for (ll& i : B) cin >> i;

	vector<ll> PA(n, A[0]), PB(n, B[0]);
	for (ll i = 1, pa = A[0], pb = B[0]; i < n; i++) {
		pa = max(A[i], pa + A[i]);
		PA[i] = pa;
		pb = max(B[i], pb + B[i]);
		PB[i] = pb;
	}

	vector<ll> SA(n, A[n-1]), SB(n, B[n-1]);
	for (ll i = n-2, pa = A[n-1], pb = B[n-1]; i >= 0; i--) {
		pa = max(A[i], pa + A[i]);
		SA[i] = pa;
		pb = max(B[i], pb + B[i]);
		SB[i] = pb;
	}

	ll res = ll(-1e18);
	for (int i = 0; i < n; i++) {
		res = max(res, PA[i] + SA[i] - A[i] + PB[i] + SB[i] - B[i]);
	}
	cout << res << endl;

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

