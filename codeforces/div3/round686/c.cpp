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
	vector<int> v(n), cont(n+1, 0);
	map<int, int> f;

	for (int& i : v) cin >> i, f[i]++;

	for (int l = 0; l < n; ) {
		int r = l+1;	

		while (r < n and v[r] == v[l]) {
			r++;
		}

		if (l and r != n) cont[v[l]]++;
		l = r;
	}

	int res = INF;
	for (int i = 0; i <= n; i++) {
		if (!cont[i]) continue;
		res = min(res, cont[i]+1);
	}
	if (!cont[v[0]] or !cont[v.back()]) res = 1;
	cout << (f.size() == 1 ? 0 : res) << endl;
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
