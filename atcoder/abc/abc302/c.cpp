#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<string> A(n);
	for (auto& i : A) cin >> i;
	sort(all(A));

	auto diff = [&](string& a, string& b) {
		int res = 0;
		for (int i = 0; i < m; i++) {
			res += a[i] != b[i];
		}
		return res;
	};

	do {
		int ok = 1;
		for (int i = 1; i < n; i++) {
			ok &= diff(A[i], A[i-1]) <= 1;
		}
		if (ok) return cout << "Yes" << endl, 0;
	} while(next_permutation(all(A)));
	cout << "No" << endl;

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

