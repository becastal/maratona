#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;

	vector<int> A(n), O(n);
	iota(all(O), 0);
	for (int& i : A) {
		cin >> i;
	}

	while (O.size() > 1) {
		int m = (int)O.size();
		vector<int> O_((m + k - 1) / k, -1);

		for (int i = 0; i < m; i++) {
			int& ou = O_[i / k];
			if (ou == -1 or array<int, 2>{A[O[i]], -O[i]} > array<int, 2>{A[ou], -ou}) {
				ou = O[i];
			}
		}
		O = move(O_);
	}
	cout << O[0] + 1 << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

