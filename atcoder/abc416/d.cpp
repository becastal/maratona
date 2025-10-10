#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n), B(n);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	sort(all(A));
	multiset<int> M(all(B));

	ll res = 0;
	for (int a : A) {
		auto it = M.lower_bound((m - a + m) % m);

		if (it == M.end()) {
			res += (a + *M.begin()) % m;
			M.erase(M.find(*M.begin()));
		} else {
			res += (a + *it) % m;
			M.erase(M.find(*it));
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
