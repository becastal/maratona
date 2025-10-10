#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int a, b, x; cin >> a >> b >> x;

	if (x & 1) {
		if (a > b) {
			for (int i = 0; i < x/2; i++) cout << "01";
			cout << string(a - x/2, '0');
			cout << string(b - x/2, '1');
		} else {
			for (int i = 0; i < x/2; i++) cout << "10";
			cout << string(b - x/2, '1');
			cout << string(a - x/2, '0');
		}
	} else {
		if (a > b) {
			for (int i = 0; i < x/2; i++) cout << "01";
			cout << string(b - x/2, '1');
			cout << string(a - x/2, '0');
		} else {
			for (int i = 0; i < x/2; i++) cout << "10";
			cout << string(a - x/2, '0');
			cout << string(b - x/2, '1');
		}
	}
	cout << endl;

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
