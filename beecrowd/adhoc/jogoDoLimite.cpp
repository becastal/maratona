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

	queue<int> q;
	int n, mesa, l; cin >> n >> mesa >> l;
	int res[2]; res[0] = 0, res[1] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int si; cin >> si;
		q.push(si);
	}
	
	int cont = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();	
		if (abs(u - mesa) <= l)
		{
			res[cont % 2] += abs(u - mesa);
			mesa = u;
		}
		cont++;
	}

	cout << res[0] << ' ' << res[1] << endl;
    
    return(0);
}
