#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int MAX = 4e5+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void Fact(vector<int>& v, int n) {
	if (n != divi[n]) Fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

map<int, int> fact(int n) {
	vector<int> v;
	Fact(v, n);

	map<int, int> R;
	for (int i : v) {
		R[i]++;
	}
	return R;
}

map<int, int> lcm(map<int, int> a, map<int, int> b) {
	for (auto [p, eb] : b) {
		a[p] = max(a[p], b[p]);
	}
	return a;
}

ll expo(ll b, ll e) {
	ll ret = 1;
	while (e) {
		if (e % 2) ret = ret * b % mod;
		e /= 2, b = b * b % mod;
	}
	return ret;
}

int solve() {
	int n; cin >> n;
	vector<int> P(n, 0);
	for (int& i : P) {
		cin >> i;
		i--;
	}

	vector<int> vis(n, 0);
	function<int(int)> dfs = [&](int u) {
		int res = 0;
		while (!vis[u]) {
			res++;
			vis[u] = 1;
			u = P[u];
		}
		return res;
	};

	map<int, int> a;
	for (int i = 0; i < n; i++) if (!vis[i]) {
		a = lcm(a, fact(dfs(i)));	
	}

	ll res = 1;
	for (auto [p, ea] : a) {
		res = (res * expo(p, ea)) % mod;
		//cout << p << ": " << ea << endl;
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;
	crivo(MAX-1);

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

