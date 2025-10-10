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
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		v[i] = c - '0';
	}

	vector<int> p = {0};
	for (int i = 0; i < n; i++) {
		p.push_back(p.back() + v[i]);
	}

	map<int, int> M;
	for (int i = 0; i <= n; i++) {
		p[i] -= i;
		M[p[i]]++;
	}

	ll res = 0;
	for (auto [a, b] : M) {
		res += (ll)b * (b - 1) / 2;
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
