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

void solve() {
	int n; cin >> n;
	vector<int> v(n), sobra;
	map<int, int> f;
	for (int& i : v) cin >> i, f[i]++;

	int res = n;
	for (auto [a, b] : f) {
		if (b & 1) res -= b - 1;
		else sobra.push_back(b);
	}

	res -= accumulate(sobra.begin(), sobra.end(), 0) - (int)sobra.size() + ((int)sobra.size() & 1);;
	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
