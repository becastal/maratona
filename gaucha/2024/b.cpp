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

vector<vector<char>> mp;

int main()
{
    _;

	int n, m; cin >> n >> m;
	mp.resize(n, vector<char>(m));
	vector<vector<int>> vis(n, vector<int>(m, 0));
	
	for (auto& l : mp)
		for (auto& c : l)	
			cin >> c;

	int b; cin >> b;

	priority_queue<pair<int, int>> ord;
	function<bool(int, int)> valido = [&] (int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and !vis[i][j] and mp[i][j] == '.';
	};

	function<void(int, int)> e = [&] (int i, int j) {
		vis[i][j] = 1;
		if (valido(i + 1, j)) e(i + 1, j);
		if (valido(i, j + 1)) e(i, j + 1);
		if (valido(i, j - 1)) e(i, j - 1);
		
		ord.push(i);
	};

	e(0, b);
	while (!ord.empty())
		cout << ord.top() << ' ', ord.pop();
	cout << endl;

	int q;
	while (cin >> q and q) {
		
	}

    
    return(0);
}
