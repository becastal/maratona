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
	string s; cin >> s;

	int cont = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') v.push_back(i), cont++;
	}
	if (!cont) {
		cout << 0 << endl;
		return;
	}

	ll res = 0;
	int agr = v[cont >> 1] - cont / 2;

	for (int i : v) {
		res += abs(agr++ - i);
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
