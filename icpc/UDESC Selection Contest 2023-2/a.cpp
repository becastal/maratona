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
	int n, m; cin >> n >> m;

	vector<int> v(n);
	vector<vector<int>> A(n);
	for (int i = 0, ki; i < n; i++) {
		cin >> ki >> v[i];
		A[i] = vector<int>(ki);
		for (int& j : A[i]) cin >> j;
	}

	ll p = 0, res = LINF;
	int lr = -1, rr = -1;
	map<int, int> f;
	for (int r = 0, l = 0; r < n; r++) {
		for (int i : A[r]) f[i]++;
		p += v[r];

		while (f.size() == m) {
			if (res > p) {
				res = p;
				lr = l;
				rr = r;
			}

			for (int i : A[l]) if (--f[i] == 0) f.erase(i);
			p -= v[l++];
		}

	}

	if (res == LINF) return cout << -1 << endl, 0;
	cout << res << endl << lr + 1 << ' ' << rr + 1 << endl;

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
