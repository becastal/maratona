#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	vector<int> P(n, -1);
	for (int l = 0, r = 0; l < n; l = r) {
		r = l + 1;
		if (S[l] == '1') continue;

		while (S[r] == '0') {
			r++;
		}

		if (r - l == 1) return cout << "NO" << endl, 0;
		P[l] = r-1;
		for (int i = l + 1, l_ = 0; i < r; i++) {
			P[i] = l + l_++;
		}
	}

	cout << "YES" << endl, 0;
	for (int i = 0; i < n; i++) {
		if (P[i] == -1) P[i] = i;
		cout << P[i] + 1 << " \n"[i == n-1];
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

