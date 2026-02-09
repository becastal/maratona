#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> R;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == '1') R.push_back(i + 1);
	}

	cout << R.size() << endl;
	for (int i : R) cout << i << ' '; cout << endl;


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

