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

	vector<int> a(n);
	for (int& i : a) cin >> i;

	map<int, int> f;
	map<int, set<int>> ff;

	for (int i = 0; i < k; i++) {
		if (ff[f[a[i]]].count(a[i])) ff[f[a[i]]].erase(a[i]);
		if (ff[f[a[i]]].empty()) ff.erase(f[a[i]]);

		ff[++f[a[i]]].emplace(a[i]);
	}


	cout << *ff.rbegin()->s.begin() << ' ';
	for (int i = k; i < n; i++) {
		ff[f[a[i-k]]].erase(a[i-k]);
		if (ff[f[a[i-k]]].empty()) ff.erase(f[a[i-k]]);
		if (--f[a[i-k]] > 0) ff[f[a[i-k]]].emplace(a[i-k]);

		ff[f[a[i]]].erase(a[i]);
		if (ff[f[a[i]]].empty()) ff.erase(f[a[i]]);
		if (++f[a[i]] > 0) ff[f[a[i]]].emplace(a[i]);
		cout << *ff.rbegin()->s.begin() << ' ';
	}
	cout << endl;

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
