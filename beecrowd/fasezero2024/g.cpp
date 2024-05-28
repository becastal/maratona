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

int solve()
{
	int n, k; cin >> n >> k;

	vector<ii> l(n);
		
	for (auto& p : l)
		cin >> p.f;

	for (auto& p : l)
		cin >> p.s;

	l.insert(l.begin(), {0, k});
	priority_queue<ii> m;

	int paradas = 0, tab = 0;
	for (int i = 0; i < l.size() - 1; i++)
	{
		int dist = l[i + 1].f - l[i].f;	
		m.push({l[i].f + l[i].s, l[i].f});

		if (dist > tab)
		{
			tab = m.top().f - m.top().s;
			m.pop();
			paradas++;
			if (dist > tab)
				return -1;
		}
		tab -= dist;
	}
	
	return paradas - 1;
}

int main()
{
    _;
	cout << solve() << endl;
    
    return(0);
}

