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
	vector<pair<int, int>> a(n);

	map<int, vector<int>> m;
	set<int> s;

	for (auto& [l, r] : a) {
		cin >> l >> r;
		m[l].push_back(r);
		s.insert(l);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	int pos = *s.begin();
	while (1) {
		for (int i : m[pos]) {
			pq.emplace(i);
		}

		int agr = pq.top(); pq.pop();

		if (pq.empty()) {
			if (s.upper_bound(pos) == s.end()) break;
			pos = *s.upper_bound(pos);
		} else {
			if (pq.top() <= pos) return cout << "No" << endl, 0;
			pos++;
		}
	}

	cout << "Yes" << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
