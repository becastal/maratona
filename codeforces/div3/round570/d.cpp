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
	map<int, int> f;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		f[x]++;
	}

	vector<int> v;
	for (auto [a, b] : f) {
		v.push_back(b);
	}
	sort(v.rbegin(), v.rend());

	int res = v[0], ult = v[0];
	for (int i = 1; i < (int)v.size(); i++) {
		if (!ult) break;

		if (v[i] >= ult) {
			res += ult - 1;
			ult--;
		} else {
			res += v[i];
			ult = v[i];
		}
	}
	cout << res << endl;
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
