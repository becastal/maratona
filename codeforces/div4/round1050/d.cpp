#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), B;

	int imp = 0;
	for (int& i : A) {
		cin >> i;
		if (i & 1) {
			imp++;
			B.push_back(i);
		}
	}

	if (!imp) return cout << 0 << endl, 0;

	ll res = 0;
	for (int i : A) if (i & 1 ^ 1) {
		res += i;	
	}

	sort(rall(B));
	int m = (B.size() + 1) / 2;
	for (int i = 0; i < m; i++) {
		res += B[i];
	}
	cout << res << endl;

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

