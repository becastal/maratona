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
typedef pair<int, int> ii;
typedef vector<set<int>> grafo;

int n, d, k;
vector<int> dist;
grafo g;

pair<string, vector<ii>> solve()
{
	cin >> n >> d >> k;
	if (d >= n) return {"NO", vector<ii>()};


	vector<int> deg(n, 0);
	vector<ii> res;
	set<ii> q;
	for (int i = 0; i < d; i++)
	{
		deg[i]++, deg[i + 1]++;
		if (deg[i] > k or deg[i + 1] > k)
			return {"NO", vector<ii>()};

		res.push_back({i, i + 1});
	}

	for (int i = 1; i < d; i++)
		q.insert({max(i, d - i), i});

	for (int i = d + 1; i < n; i++)
	{
		while (!q.empty() and deg[q.begin()->s] == k)
			q.erase(q.begin());
		if (q.empty() or q.begin()->f == d)
			return {"NO", vector<ii>()};

		deg[i]++, deg[q.begin()->s]++;
		res.push_back({i, q.begin()->s});
		q.insert({q.begin()->f + 1, i});	
	}
	return {"YES", res};
}

int main()
{
    _;

	auto r = solve();
	cout << r.f << endl;
	for (auto [u, v] : r.s)
		cout << u + 1 << ' ' << v + 1 << endl;
    
    return(0);
}
