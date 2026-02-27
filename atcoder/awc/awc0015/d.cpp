#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, c; cin >> n >> m >> c;
	vector<int> A(n);
	multiset<int> B;

	for (int& i : A) cin >> i;
	for (int i = 0, x; i < m; i++) { 
		cin >> x;
		B.insert(x);
	}

	sort(all(A));
	int res = 0;
	for (int& i : A) {
		auto it = B.upper_bound(i);
		if (it == B.begin()) continue;
		res += c;		
		B.erase(B.find(*prev(it)));
	}
	cout << res << endl;

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

