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
	setIO("convention2");

	ll n; cin >> n;
	vector<pair<ll, ll>> a(n);
	vector<tuple<ll, ll, ll>> as(n);

	for (ll i = 0, l, t; i < n; i++) {
		cin >> l >> t;
		a[i] = {l, t};
		as[i] = {l, t, i};
	}
	sort(as.begin(), as.end());

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll res = 0, pos = 0, t = get<0>(as[0]);
	while (pos < n or pq.size()) {
		if (pq.empty() and pos < n) {
			t = max(t, get<0>(as[pos]));
		}

		while (pos < n and t >= get<0>(as[pos])) {
			pq.emplace(get<2>(as[pos++]));
		}

		if (pq.size()) {
			auto [li, ti] = a[pq.top()]; pq.pop();
			res = max(res, t - li);
			t += ti;
		}
	}
	cout << res << endl;

    return(0);
}
