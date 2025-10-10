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

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = max((i ? a[i-1] : -INF), v[i] + i);
	}

	for (int i = n-1; i >= 0; i--) {
		b[i] = max((i != n-1 ? b[i+1] : -INF), v[i] - i);
	}

	int res = 0;
	for (int i = 1; i < n-1; i++) {
		res = max(res, a[i-1] + v[i] + b[i+1]);
	}
	cout << res << endl;
}

int main()
{
    _;
	setIO("");

	int t; cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
