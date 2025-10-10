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
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n);

	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	set<int> s;
	for (int i = 0; i < n; i++) {
		if (b[i] == -1) continue;
		s.insert(a[i] + b[i]);
		if (s.size() > 1) return cout << 0 << endl, 0;
	}

	if (s.size()) {
		int ok = 1;
		for (int i = 0; i < n and ok; i++) {
			if (b[i] == -1) {
				int x = *s.begin() - a[i];
				ok &= x >= 0 and x <= k;
			}
		}
		return cout << ok << endl, 0;
	}

	int res = (*min_element(a.begin(), a.end()) + k) - *max_element(a.begin(), a.end()) + 1;
	cout << max(0, res) << endl;

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
