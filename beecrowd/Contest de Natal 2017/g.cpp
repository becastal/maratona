#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<int> P(n);

	for (int& i : P) {
		cin >> i;
	}

	int dp = (1 << 5), tudo = (1 << 11) - 1;
	for (int i = 0; i < n; i++) {
		int dp_ = ((dp << P[i]) | (dp >> P[i])) & tudo;
		if (!dp_) return cout << "Ho Ho Ho!" << endl, 0;
		dp = dp_;
	}
	cout << "Feliz Natal!" << endl;

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

