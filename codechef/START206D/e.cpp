#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	if (n == 1) return cout << "1" << endl, 0;
	if (n == 2) return cout << "1 2" << endl, 0;
	if (n == 3) return cout << "2 1 3" << endl, 0;

	for (int i = 2; i <= n; i += 2) {
		cout << i << ' ';
	}
	for (int i = 1; i <= n; i += 2) {
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

