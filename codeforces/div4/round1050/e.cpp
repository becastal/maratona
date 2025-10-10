#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;

	map<int, int> F;
	vector<int> A(n);
	for (int& i : A) cin >> i, F[i]++;

	map<int, int> C;
	for (auto [a, b] : F) {
		if (b % k) return cout << 0 << endl, 0;
		C[a] = b / k;
	}

	// agora eh subarray with required multiset
	ll res = 0;
	for (int r = 0, l = 0; r < n; r++) {
		C[A[r]]--;

		while (C[A[r]] < 0){ 
			C[A[l++]]++;
		}

		res += r - l + 1;
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

