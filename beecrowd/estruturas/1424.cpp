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

	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> v(1000010);

		for (int i = 0, x; i < n; i++) {
			cin >> x;
			v[x].push_back(i+1);
		}

		while (m--) {
			int k, x; cin >> k >> x; k--;
			if (k >= (int)v[x].size()) cout << 0 << endl;
			else cout << v[x][k] << endl;
		}
	}
    
    return(0);
}
