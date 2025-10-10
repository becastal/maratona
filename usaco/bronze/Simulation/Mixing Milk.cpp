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
	setIO("mixmilk");

	vector<pair<ll, ll>> v(3);
	for (auto& [c, m] : v) cin >> c >> m;

	for (int i = 0; i < 100; i++) {
		auto& [ci, mi] = v[i%3];
		auto& [cj, mj] = v[(i+1)%3];

		mj += mi, mi = max(mj - cj, 0LL);
		mj = min(mj, cj);
	}

	for (auto [c, m] : v) {
		cout << m << endl;
	}

    return(0);
}
