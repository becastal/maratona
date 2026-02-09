#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int a, b, c; cin >> a >> b >> c;
	for (int i = 0; i < 10000; i++) {
		if ((a + i) % (b + i) == 0 and (a + i) / (b + i) == c) return cout << "Yes" << endl, 0;	
	}
	cout << "No" << endl;

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

