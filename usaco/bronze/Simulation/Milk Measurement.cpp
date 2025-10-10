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

int main()
{
    _;
	setIO("measurement");

	map<string, int> M = {
		{"Bessie", 7},
		{"Elsie", 7},
		{"Mildred", 7}
	};

	int n; cin >> n;
	vector<tuple<int, string, int>> v(n);
	for (auto& [pos, s, x] : v) {
		cin >> pos >> s >> x;
	}
	sort(v.begin(), v.end());

	int res = 0;
	for (auto [pos, s, x] : v) {
		set<string> a;
		int mx = -INF;
		for (auto [i, j] : M) mx = max(mx, j);
		for (auto [i, j] : M) if (j == mx) a.insert(i);

		M[s] += x;

		mx = -INF;
		set<string> b;
		for (auto [i, j] : M) mx = max(mx, j);
		for (auto [i, j] : M) if (j == mx) b.insert(i);
		res += a != b;
	}
	cout << res << endl;

    return(0);
}
