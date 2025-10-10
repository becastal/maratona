#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int a, b, res = 0; cin >> a >> b;

	while (a or b) {
		if (b) {
			b--;
			if (a >= 2) a -= 2;
			else if (a == 1) a--, b--;
			else b -= 2;
			res += 2;
		} else {
			a -= 3;
			res++;
		}
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

