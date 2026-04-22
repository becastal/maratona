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
	vector<array<int, 2>> A;
	for (int l = 0, r; l < n; l = r) {
		r = l + 1;
		while (r < n and S[l] == S[r]) {
			r++;
		}
		A.push_back({S[l] == 'x', r - l});
	}

	int m = (int)A.size(), res = 0;
	for (int i = 0; i < m; i++) {
		if (!A[i][0]) {
			if (!i or A[i-1][1] < A[i][1]) return cout << -1 << endl, 0;
			res++;
		}
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

