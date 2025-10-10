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
	vector<int> v(n), vis(n, 0); 
	for (int& i : v) cin >> i;

	int or_agr = 0;
	for (int i = 0; i < min(31, n); i++) {
		int mx = 0, ii = -1;

		for (int j = 0; j < n; j++) {
			if (vis[j]) continue;

			if ((or_agr | v[j]) > mx) {
				mx = (or_agr | v[j]);
				ii = j;
			}
		}

		vis[ii] = 1;
		cout << v[ii] << ' ';
		or_agr |= v[ii];
	}

	for (int i = 0; i < n; i++) {
		if (!vis[i]) cout << v[i] << ' ';
	}
	cout << endl;
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
