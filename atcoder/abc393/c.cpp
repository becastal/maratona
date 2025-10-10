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

	int res = 0;
	set<pair<int, int>> ja;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;	
		if (u == v) {
			res++;
			continue;
		}
		
		if (u > v) swap(u, v);
		res += ja.count(pair<int, int>(u, v));
		ja.emplace(u, v);
	}
	cout << res << endl;
    
    return(0);
}
