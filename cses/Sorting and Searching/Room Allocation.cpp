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

int solve() {
	int n; cin >> n;

	vector<int> res(n);
	vector<tuple<int, int, int>> ev;
	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		ev.emplace_back(l, 0, i);	
		ev.emplace_back(r, 1, i);	
	}

	priority_queue<int> livre;
	for (int i = 0; i < n; i++) {
		livre.emplace(-i);
	}

	sort(ev.begin(), ev.end());
	for (auto [pos, tp, u] : ev) {
		if (tp == 0) { // chegando
			res[u] = -livre.top(); livre.pop();
		} else {
			livre.emplace(-res[u]);
		}
	}

	cout << *max_element(res.begin(), res.end()) + 1 << endl;
	for (int i : res) cout << i + 1 << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
