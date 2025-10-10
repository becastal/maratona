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
	int n; cin >> n;

	vector<int> cont(3, 0);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		cont[x % 3]++;
	}

	int res = cont[0], us = min(cont[2], cont[1]);
	res += us;
	res += (cont[1] - us) / 3;
	res += (cont[2] - us) / 3;
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
