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

	int ok = 1;
	for (int p : {0, 1}) {
		int vi1 = 0, vi2 = 0;

		for (int i = p; i < n; i += 2) {
			vi1 |= (A[i] == 1);
			vi2 |= (A[i] == 2);
		}
		if (vi2) ok &= vi1;
	}
	cout << (ok ? "No" : "Yes") << endl;


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

