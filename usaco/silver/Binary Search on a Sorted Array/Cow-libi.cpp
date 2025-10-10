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
	setIO("");

	int g, n; cin >> g >> n;
	vector<tuple<ll, ll, ll>> v(g);

	for (auto& [t, x, y] : v) {
		cin >> x >> y >> t;	
	}
	sort(v.begin(), v.end());

	auto da = [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
		auto [ta, xa, ya] = a;
		auto [tb, xb, yb] = b;
		return (xa-xb) * (xa-xb) + (ya-yb) * (ya-yb) <= (ta-tb) * (ta-tb);
	};

	int res = 0;
	for (int i = 0, x, y, t; i < n; i++) {
		cin >> x >> y >> t;	
		int ii = lower_bound(v.begin(), v.end(), make_tuple(t, x, y)) - v.begin();
		
		int ok = 0;
		if (ii) ok |= !da(make_tuple(t, x, y), v[ii-1]);
		if (ii < v.size()) ok |= !da(make_tuple(t, x, y), v[ii]);
		
		res += ok;
	}
	cout << res << endl;

    return(0);
}
