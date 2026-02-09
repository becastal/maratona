#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, s = 0; cin >> n;
	vector<int> D(n);
	for (int& i : D) {
		cin >> i;
		s += i;
	}

	for (int i = 0, p = 0; i < n; i++) {
		p += D[i];
		if (p > s / 2) return cout << i + 1 << ' ' << D[i] - (p - s / 2) + 1 << endl, 0;
	}

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

