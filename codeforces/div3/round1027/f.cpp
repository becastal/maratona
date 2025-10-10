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

const int MAX = 1e6+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

vector<int> fact_(int x) {
	if (x == 1) return vector<int>();
	vector<int> f;
	fact(f, x);
	return f;
}

int solve() {
	int x, y, k; cin >> x >> y >> k;

	int g = gcd(x, y);
	auto fx = fact_(x / g), fy = fact_(y / g);

	auto cont = [&k](vector<int> a) {
		int n = (int)a.size();
		if (!n) return 0;
		
		int res = n;
		function<void(int, int)> dfs = [&](int u, int b) {
			if (u == n) {
				res = min(res, v);	
				return;
			}

		};
		dfs(0);
	};

	if ((fx.size() and *max_element(fx.begin(), fx.end()) > k) or
		(fy.size() and *max_element(fy.begin(), fy.end()) > k)) return cout << -1 << endl, 0;
	
	cout << cont(fx) + cont(fy) << endl;

	return(0);
}

int main()
{
    _;
	crivo(MAX-1);

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
