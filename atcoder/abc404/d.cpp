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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<int> c(n);
	for (int& i : c) cin >> i;

	vector<set<int>> a(n);

	for (int i = 0, k; i < m; i++) {
		cin >> k;
		for (int j = 0, x; j < k; j++) {
			cin >> x; x--;
			a[x].insert(i);
		}
	}

	vector<int> p = {1};
	for (int i = 0; i < 12; i++) {
		p.push_back(p.back() * 3);
	}

	auto b = [n](int x) {
		vector<int> res;
		while (x) {
			res.push_back(x % 3);
			x /= 3;
		}
		while(res.size() < n) res.push_back(0);
		return res;
	};

	// na real eh pra iterar em 3 ** n. dai da pra simular ir duas vezes no mesmo zoo.
	// obv nao vale a pena ir mais de duas vezes no mesmo.
	ll res = LINF;
	for (int i = 1; i < p[n]; i++) {
		ll agr = 0;
		vector<int> vis(m, 0), b3 = b(i);

		for (int j = 0; j < n; j++) {
			agr += b3[j] * c[j];
			for (int ii : a[j]) vis[ii] = min(vis[ii] + b3[j], 2);
		}
		if (count(vis.begin(), vis.end(), 2) == m) res = min(res, agr);
	}
	cout << res << endl;
    
    return(0);
}
