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

const int MAX = 1e5 + 10;
vector<bool> posso(MAX, 0);
vector<int> bins;

void build(int i)
{
	if (i >= MAX or posso[i]) return;
	posso[i] = true;
	
	for (int j : bins)
		build(i * j);
}

int main()
{
    _;

	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		bins.push_back(u);
		if (u * 10 < MAX)
			q.push(u * 10), q.push(u * 10 + 1);
	}

	build(1);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << (posso[n] ? "YES" : "NO") << endl;
	}
    
    return(0);
}
