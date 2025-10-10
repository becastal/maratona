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

const int mod = 998244353;
const int MAX = 1e5+10;
int p2[MAX];

int solve() {
	int n; cin >> n;
	vector<int> p(n), q(n);

	for (int& i : p) cin >> i;
	for (int& i : q) cin >> i;

	priority_queue<pair<int, int>> pq;
	for (int i = 0, r = 0, mxr = -1, l = 0, mxl = -1; i < n; i++) {
		if (mxr < p[i]) {
			mxr = p[i];
			r = i;
		}
		if (mxl < q[i]) {
			mxl = q[i];
			l = i;
		}

		pair<int, int> R(p[r], q[i-r]),
					   R_(q[i-r], p[r]),
					   L(q[l], p[i-l]),
					   L_(p[i-l], q[l]);
		auto [a, b] = max({R, R_, L, L_});
		cout << (p2[a] + p2[b]) % mod << " \n"[i==n-1];
	}

	return(0);
}

int main()
{
    _;

	p2[0] = 1;
	for (int i = 1; i < MAX; i++) {
		p2[i] = (p2[i-1] * 2) % mod;
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
