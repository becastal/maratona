#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, d; cin >> n >> d;

	vector<int> A(d);
	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		for (int j = 0; j < d; j++) {
			A[j] |= S[j] == 'x';
		}
	}

	int res = 0;
	for (int l = 0, r; l < d; l = r) {
		r = l + 1;
		if (A[l]) continue;

		while (r < d and !A[r]) {
			r++;
		}

		res = max(res, r - l);
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

