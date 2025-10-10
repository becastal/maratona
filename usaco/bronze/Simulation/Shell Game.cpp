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
	setIO("shell");

	int n; cin >> n;
	vector<tuple<int, int, int>> v(n);
	for (auto& [a, b, g] : v) cin >> a >> b >> g;

	int res = 0;
	for (int i = 1; i <= 3; i++) {
		int agr = 0;

		vector<int> p(4, 0);
		p[i] = 1;
		for (auto [a, b, g] : v) {
			swap(p[a], p[b]);
			agr += p[g];
		}

		res = max(res, agr);
	}
	cout << res << endl;

    return(0);
}
