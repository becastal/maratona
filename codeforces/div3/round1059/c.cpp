#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int a, b; cin >> a >> b;
	if (__builtin_clz(b) < __builtin_clz(a)) return cout << -1 << endl, 0;

	vector<int> R;
	for (int i = 0; i < 31; i++) if ((1 << i) <= a and ((a & (1 << i)) == 0)) {
		R.push_back(1 << i);
		a |= (1 << i);
	}

	for (int i = 0; i < 31; i++) if ((1 << i) <= a and ((b & (1 << i)) == 0)) {
		R.push_back(1 << i);
	}

	cout << R.size() << endl;
	for (int i : R) {
		cout << i << ' ';
	}
	cout << endl;

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

