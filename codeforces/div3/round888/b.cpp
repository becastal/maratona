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

	vector<int> res(n), p(n);
	vector<vector<int>> v(2);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		v[x&1].push_back(x);
		p[i] = x&1;
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	vector<int> pos = {0, 0};
	for (int i = 0; i < n; i++) {
		res[i] = v[p[i]][pos[p[i]]];	
		pos[p[i]]++;
	}
	cout << (is_sorted(res.begin(), res.end()) ? "YES" : "NO") << endl;
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
