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

int main()
{
    _;

	int n, t; cin >> n >> t;
	priority_queue<pair<int, string>> pq;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int x; cin >> x;
		pq.emplace(x, s);
	}

	vector<vector<string>> times(t);
	int i = 0;
	while (!pq.empty()) {
		times[i].push_back(pq.top().s);
		pq.pop();
		i++; i %= t;
	}

	for (int i = 0; i < t; i++) {
		cout << "Time " << i + 1 << endl;
		sort(times[i].begin(), times[i].end());
		for (string s : times[i]) cout << s << endl;
		cout << endl;
	}
    
    return(0);
}
