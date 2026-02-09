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
	for (int& i : A) cin >> i;

	vector<int> P(n);
	iota(all(P), 0);
	sort(all(P), [&](int i, int j) { return A[i] < A[j]; });

	vector<int> R(n, -1);
	for (int i = 1; i < n-1; i++) {
		R[P[i]] = max(0, (A[P[i+1]] + A[P[i]]) / 2 - (A[P[i]] + A[P[i-1]]) / 2);
	}
	for (int i = 0; i < n; i++) {
		cout << R[i] << " \n"[i == n-1];
	}

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

