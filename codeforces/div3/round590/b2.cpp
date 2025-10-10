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
	int n, k; cin >> n >> k;
	set<int> s;
	queue<int> q;

	for (int i = 0, x; i < n; i++) {
		cin >> x;

		if (s.count(x)) continue;

		if (q.size() == k) {
			int ult = q.front();
			q.pop();
			s.erase(ult);
		} 
		q.push(x);
		s.insert(x);
	}

	vector<int> res;
	cout << q.size() << endl;
	while (q.size()) {
		res.push_back(q.front());
		q.pop();
	}
	reverse(res.begin(), res.end());
	for (int i : res) cout << i << ' '; cout << endl;

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
