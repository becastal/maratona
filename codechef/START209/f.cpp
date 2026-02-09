#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n), B(m);
	map<int, int> Fa, Fb;

	for (int& i : A) {
		cin >> i;
		Fa[i]++;
	}
	for (int& i : B) {
		cin >> i;
		Fb[i]++;
	}

	ll res = accumulate(all(A), 0LL) + accumulate(all(B), 0LL);
	for (auto [a, ca] : Fa) {
		int cb = Fb[a];

		if (ca + cb > n) {
			res -= 2LL * a * ((ca + cb) - n);
		}
	}
	cout << res << endl;

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

