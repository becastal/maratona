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
	map<int, int> val; val[0] = INF;
	set<int> tam; tam.insert(INF);

	auto coloca = [&](int x) {
		auto& [ant, muda] = val.lower_bound(x);	
		tam.remove(muda);
		tam.insert(x - ant);
		muda = x - ant;
		val[x] = val[*val.upper_bound(x)] - x;
	};

	auto tira = [&](int x) {
		
	};

	auto query = [&](int x) {
		int q = *tam.lower_bound(x);
		if (q == INF) return *tam.rbegin();
		return q;
	};

	int n; cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		coloca(x);
	}

	int m; cin >> m;
	for (int i = 0, x; i < m; i++) {
		char c; cin >> c >> x;
		if (c == '+') {
			coloca(x);
		} else if (c == '-') {
			tira(x);
		} else {
			cout << query(x) << ' ';
		}
	}
	cout << endl;
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
