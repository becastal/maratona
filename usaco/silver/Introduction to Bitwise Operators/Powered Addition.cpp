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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	int res = 0;
	for (int i = 1, agr = v[0]; i < n; i++) {
		agr = max(agr, v[i]);
		if (agr - v[i]) res = max(res, 32 - __builtin_clz(agr - v[i]));
	}
	cout << res << endl;
}

int main()
{
    _;
	setIO("");

	int t; cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
