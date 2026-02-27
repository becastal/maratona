#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve(int a, int b, int c) {
	if (!a and !b and !c) return 0;

	if (c - b == b - a) {
		return cout << "AP " << c + (b - a) << endl, 0;	
	}

	if (c % b == 0 and b % a == 0 and c / b == b / a) {
		return cout << "GP " << c * (c / b) << endl, 0;
	}
	assert(0);

	return(0);
}

signed main()
{
    _;

	int t = 1, a, b, c; //cin >> t;
	while (cin >> a >> b >> c) {
		solve(a, b, c);
	}
    
    return(0);
}
