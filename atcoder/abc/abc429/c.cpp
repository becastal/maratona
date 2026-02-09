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

	vector<ll> Cl(n+1, 0), Cr(n+1, 0);
	for (int i : A) Cr[i]++;

	ll res = 0, prod = 0;
	for (int j = 0; j < n; j++) {
		if (j) {
			Cl[A[j-1]]++;
			prod += Cr[A[j-1]];
		}
		prod -= Cl[A[j]];
		Cr[A[j]]--;

		res += Cl[A[j]] * ((n - j - 1) - Cr[A[j]]);
		res += Cr[A[j]] * (j - Cl[A[j]]);
		res += prod - Cl[A[j]] * Cr[A[j]];
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

