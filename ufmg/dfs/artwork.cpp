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

vector<ii> movs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
vector<vector<bool>> avel;
int m, n, k; 

void bfs(ii s, k)
{
	vector<vector<int>> d (m, vector<int> (n, INF));
	queue<ii> q;
	q.push(s);
	d[s.f][s.s] = 0;

	while (!q.empty())
	{
		ii u = q.front();
	}
}

int main()
{
    _;

	cin >> m >> n >> k;

	avel.resize(m, vector<bool> (n, true));

	// bfs multi a partir de cada k
    
    return(0);
}
