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

vector<pair<int, int>> movs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
vector<vector<int>> mapa, vis;
int l, c;
pair<int, int> pos;

bool valido(pair<int, int> p)
{
	return p.f >= 0 and p.s >= 0 and p.f < l and p.s < c and mapa[p.f][p.s] and !vis[p.f][p.s];
}

int main()
{
    _;

	cin >> l >> c;
	cin >> pos.f >> pos.s;
	pos.f--, pos.s--;

	mapa = vector<vector<int>> (l, vector<int>(c));
	vis = vector<vector<int>> (l, vector<int>(c, 0));
	
	for (auto& li : mapa)
		for (auto& ci : li)
			cin >> ci;

	int i = 0;
	while (true)
	{
		vis[pos.f][pos.s] = 1;
		pair<int, int> antes = pos;
		
		for (auto m : movs)
			if (valido({pos.f + m.f, pos.s + m.s}))
			{
				pos.f += m.f, pos.s += m.s;
				break;
			}


		if (pos.f == antes.f and pos.s == antes.s) break;
	}

	cout << pos.f + 1 << ' ' << pos.s + 1 << endl;

    
    return(0);
}
