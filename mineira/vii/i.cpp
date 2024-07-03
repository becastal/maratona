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

int n, m;
vector<vector<char>> mp;
set<ii> mesas;

int main()
{
    _;
	cin >> n >> m;
	mp.resize(n, vector<char>(m));

	for (auto l : mp)
		for (auto& c : l)
			cin >> c;

	int k; cin >> k;
	while (k--)
	{
		int ci, li; cin >> ci >> li;
		mesas.insert({ci, li});
	}
    
    return(0);
}
