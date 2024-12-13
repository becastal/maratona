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
	int n, k; cin >> n >> k;

	map<int, int> M;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		M[x]++;
	}

	vector<pair<int, int>> v;
	for (auto& [a, b] : M) {
		v.emplace_back(a, b);
	}

	for (int l = 0; l < n;) {

	}
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
