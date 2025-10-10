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
	vector<int> v(n);
	map<int, int> f;
	for (int& i : v) cin >> i, f[i]++;

	if (v[0] == v.back()) {
		cout << (f[v[0]] >= k ? "YES" : "NO") << endl;
		return;
	}

	int i = 0, j = n-1, l = 0, r = 0;
	for (; i < n and l < k; i++) {
		l += (v[i] == v[0]);
	}

	for (; j >= 0 and r < k; j--) {
		r += (v[j] == v.back());
	}

	cout << ((i - 1) < (j + 1) ? "YES" : "NO") << endl;
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
