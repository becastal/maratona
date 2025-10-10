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

vector<int> B = { 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, };
int solve() {
	int a, b; cin >> a >> b;

	cout << (ll)a * (upper_bound(B.begin(), B.end(), b) - B.begin()) << endl;

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
