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

int main()
{
    _;
	setIO("");

	int n, m; cin >> n >> m;
	priority_queue<pair<int, int>> pq;
	
	vector<int> res(n), vis(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> res[i];
		pq.emplace(res[i], i);
	}

	while (pq.size()) {
		auto [x, i] = pq.top(); pq.pop();
		if (vis[i]) continue;
		vis[i] = 1;

		if (i) res[i-1] = max(res[i-1], x - m), pq.emplace(res[i-1], i-1);
		if (i!=n-1) res[i+1] = max(res[i+1], x - m), pq.emplace(res[i+1], i+1);
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i==n-1];
	}

    return(0);
}
