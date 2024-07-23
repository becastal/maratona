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

vector<ii> movs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<char>> mp(n, vector<char>(m));
	for (auto& l : mp)
		for (auto& c : l)
			cin >> c;

	function<bool(ii, ii)> valido = [&] (ii pos, ii movi) {
		ii npos = {pos.f + movi.f, pos.s + movi.s};
		return npos.f >= 0 and npos.s >= 0 and npos.f < n and npos.s < m;
	};

	pair<int, int> p; cin >> p.f >> p.s; p.f--, p.s--;
	bool b = true;
	for (auto mov : movs)
		if (valido(p, mov))
			b &= (mp[p.f + mov.f][p.s + mov.s] == 'x');

	cout << (b ? "yes" : "no") << endl;
	
    
    return(0);
}
