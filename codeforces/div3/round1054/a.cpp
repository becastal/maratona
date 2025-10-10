#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, menos = 0, res = 0; cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (!x) res++;
		menos += x == -1;
	}
	if (menos & 1) res += 2;
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

