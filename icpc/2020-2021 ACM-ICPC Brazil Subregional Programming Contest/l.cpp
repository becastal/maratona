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
vector<ii> movs = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

int l, c, n; 
vector<vector<char>> mp;
vector<vector<set<string>>> cont;

bool valido(ii a)
{
	return a.f >= 0 and a.s >= 0 and a.f < l and a.s < c;
}

void busca(vector<int>& s, string& si)
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < c; j++)
		{
			for (auto mov : movs)
			{
				auto t = s;
				vector<ii> poss;

				for (int k = 0; k < si.size(); k++)
				{
					ii v = {i + mov.f * k, j + mov.s * k};
					poss.push_back(v);
					if (valido(v)) t[mp[v.f][v.s] - 'A']--;
				}

				bool res = true;
				for (int jj : t)
				{
					if (jj != 0)
						res = false;
					if (!res) break;
				}

				if (res)
					for (ii pos : poss)
						if (valido(pos)) cont[pos.f][pos.s].insert(si);
			}
		}
}

int main()
{
    _;
	
	cin >> l >> c;
	mp.resize(l, vector<char> (c));
	cont.resize(l, vector<set<string>> (c));
	for (auto& li : mp)
		for (auto& ci : li)
			cin >> ci;

	cin >> n;
	while (n--)
	{
		string si; cin >> si;
		vector<int> s(26, 0);
		for (char ci : si)
			s[ci - 'A']++;
		busca(s, si);
	}

	//for (int i = 0; i < l; i++)
	//{
	//	for (int j = 0; j < c; j++)
	//		cout << cont[i][j].size() << ' ';
	//	cout << endl;
	//}


	int res = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < c; j++)
			if (cont[i][j].size() > 1)
				res++;
	
	cout << res << endl;
    
    return(0);
}
