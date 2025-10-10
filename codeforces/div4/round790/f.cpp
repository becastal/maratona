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
	map<int, int> f;

	for (int i = 0, x; i < n; i++) {
		cin >> x; f[x]++;
	}

	vector<int> v;
	for (auto [a, fa] : f) {
		if (fa < k) continue;
		v.push_back(a);
	}

	int tam = 0, li, ri;
	for (int l = 0, r; l < (int)v.size(); ) {
		r = l;
		while (r < (int)v.size()-1 and v[r+1] == v[r]+1) {
			r++;
		}

		if (v[r] - v[l] + 1 > tam) {
			tam = r - l + 1;
			li = v[l];
			ri = v[r];
		}
		l = r+1;
	}

	if (tam) {
		cout << li << ' ' << ri << endl;
	} else {
		cout << -1 << endl;
	}
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
