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

void solve() {
	int n0, n1, n2; cin >> n0 >> n1 >> n2;

	if (!n1) {
		if (n0) cout << string(n0+1, '0') << endl;
		else cout << string(n2+1, '1') << endl;
		return;
	}

	string res = "";
	for (int i = 0; i < n1 + 1; i++) {
		res.push_back(i & 1 ? '0' : '1');
	}

	res.insert(1, string(n0, '0'));
	res.insert(0, string(n2, '1'));
	cout << res << endl;
}

int main()
{
    _;

	// 11111100000

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
