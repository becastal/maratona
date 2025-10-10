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

	int n; cin >> n;
	vector<int> p(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> v[i]; p[i]--;
	}

	ll s = accumulate(v.begin(), v.end(), 0LL);
	vector<int> vis(n, 0);

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;

		int u;
		for (u = i; !vis[u]; u = p[u]) {
			vis[u] = 1;
		}

		if (vis[u] == 1) {
			ll agr = v[u];

			for (int u_ = p[u]; u_ != u; u_ = p[u_]) {
				agr = min(agr, (ll)v[u_]);
			}

			s -= agr;
		}
		
		for (u = i; vis[u] == 1; u = p[u]) {
			vis[u] = 2;
		}
	}

	cout << s << endl;

    return(0);
}
