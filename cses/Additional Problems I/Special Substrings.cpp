#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	string S; cin >> S;

	string S_ = S;
	sort(all(S_));
	S_.erase(unique(all(S_)), S_.end());

	int k = (int)S_.size();
	vector<int> C(k);
	map<vector<int>, int> M;	
	M[C] = 1;

	ll res = 0;
	for (char c : S) {
		c = lower_bound(all(S_), c) - S_.begin();
		C[c]++;

		int mx = INT_MIN;
		for (int i = 0; i < k; i++) {
			mx = max(mx, C[i]);
		}

		vector<int> C_ = C;
		for (int i = 0; i < k; i++) {
			C_[i] -= mx;
		}
		res += M[C_];
		M[C_]++;
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

