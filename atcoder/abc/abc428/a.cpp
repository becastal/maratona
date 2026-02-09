#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int s, a, b, x, p = 0;
	cin >> s >> a >> b >> x;

	for (int i = 0; i < x; i++) {
		if (i % (a + b) < a) {
			p += s;
		}
	}
	cout << p << endl;

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

