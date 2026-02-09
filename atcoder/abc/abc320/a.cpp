#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int a, b; cin >> a >> b;

	int c = 1, d = 1;
	for (int i = 0; i < b; i++) {
		c *= a;
	}
	for (int i = 0; i < a; i++) {
		d *= b;
	}
	cout << c + d << endl;


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

