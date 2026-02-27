#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, mx = 0; cin >> n;

	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
		mx = max(mx, (int)i.size());
	}

	for (auto& i : A) {
		int m = (int)i.size(), h = (mx - m) / 2;
		cout << string(h, '.') << i << string(h, '.') << endl;
	}

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

