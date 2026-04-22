#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> A(n), B(m);
	for (int& i : A) {
		cin >> i;
	}
	for (int& i : B) {
		cin >> i;
	}
	sort(all(B));

	string S; cin >> S;
	map<int, vector<int>> morre;
	
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(all(B), A[i]);
		if (it != B.begin()) {
			morre[*prev(it) - A[i]].push_back(i);
		}

		it = upper_bound(all(B), A[i]);
		if (it != B.end()) {
			morre[*it - A[i]].push_back(i);
		}
	}

	// LLLRRRRR
	// 0 -1 -2 -3 -2 -1 0 1 2
	//    ^                 ^
	
	vector<int> Foi(n);
	for (int i = 0, p = 0, res = n; i < k; i++) {
		p += (S[i] == 'L' ? -1 : +1);

		for (int j : morre[p]) {
			if (!Foi[j]) {
				res--;
			}
			Foi[j] = 1;
		}
		morre[p].clear();
		cout << res << " \n"[i==k-1];
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

