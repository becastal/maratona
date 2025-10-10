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
	int n, k; cin >> n >> k;

	vector<string> res(n, string(n, '.'));

	for (int i = 0, j = 0; i < n and k; ) {
		res[i][j] = 'R';	
		i += 2, j += 2;
		k--;
	}

	if (k) {
		cout << -1 << endl;
		return;
	}

	for (auto s : res) cout << s << endl;
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
