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

	int res = 0, q = 0;
	vector<int> cont(4, n);
	for (int i = 0; i < 4*n; i++) {
		char c; cin >> c;
		if (c == '?') continue;
		int j = c - 'A';
		res += !!cont[j];
		cont[j] = max(0, cont[j]-1);
	}

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
