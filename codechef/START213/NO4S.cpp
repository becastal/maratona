#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	vector<int> C(4);

	int n; cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		C[x]++;
	}

	cout << min(C[1], C[3]) + max(0, C[2] - 1) << endl;

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

