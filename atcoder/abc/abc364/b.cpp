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

	int n, m; cin >> n >> m;
	int si, sj; cin >> si >> sj; si--, sj--;
	vector<vector<char>> v(n, vector<char>(m));

	for (auto& l : v) for (auto& c : l) cin >> c;
	string movs; cin >> movs;

	auto valido = [&] (int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < m and v[i][j] == '.';
	};

	map<char, int> mi = {{'U', -1}, {'D', 1}}, mj = {{'L', -1}, {'R', 1}};
	for (char c : movs) {
		int nsi = si + mi[c], nsj = sj + mj[c];
		if (valido(nsi, nsj)) {
			si = nsi, sj = nsj;	
		}
	}

	cout << si+1 << ' ' << sj+1 << endl;
    
    return(0);
}
