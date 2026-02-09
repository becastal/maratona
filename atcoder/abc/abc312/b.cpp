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
	for (auto& i : A) {
		cin >> i;
	}

	for (int i = 0; i <= n - 9; i++) {
		for (int j = 0; j <= m - 9; j++) {
			int ok = 1;

			for (int ii = 0; ii < 3 and ok; ii++) {
				ok &= A[i + ii].substr(j + 0, 4) == "###.";
				ok &= A[i + 6 + ii].substr(j + 5, 4) == ".###";
			}
			ok &= A[i + 3].substr(j + 0, 4) == "....";
			ok &= A[i + 5].substr(j + 5, 4) == "....";

			if (ok) {
				cout << i + 1 << ' ' << j + 1 << endl;
			}
		}
	}

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

