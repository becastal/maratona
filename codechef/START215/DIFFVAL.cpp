#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	string S; cin >> S;

	vector<int> C(2, 0);
	for (char c : S) {
		C[c-'0']++;
	}

	for (int i = 1; i <= k; i++) {
		int l = (n - i) / k + 1;
		//cout << l << ' ';

		if (l & 1 ^ 1) {
			C[0] -= l / 2, C[1] -= l / 2;
		} else {
			int a = C[1] >= C[0], b = a ^ 1;
			C[a] -= l / 2 + 1, C[b] -= l / 2;
		}
		if (C[0] < 0 or C[1] < 0) return cout << "No" << endl, 0;
	}
	cout << "Yes" << endl;

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

