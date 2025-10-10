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
	int n, m; cin >> n >> m;
	vector<int> v((1<<n), 1);

	for (int i = 0, x; i < m; i++) {
		cin >> x;
		v[x-1] = 0;
	}

	queue<vector<int>> q;
	for (int i = 0; i < (1 << n); i += 2) {
		q.push({v[i], v[i+1]});	
	}

	int res = 0;
	vector<int> agr;
	while (q.size()) {
		auto vi = q.front(); q.pop();	
		int a = vi[0], b = vi[1];

		if (!a ^ !b) res++;
		agr.push_back(a or b);

		if (agr.size() == 2) {
			q.emplace(agr);
			agr.clear();
		}
	}

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
