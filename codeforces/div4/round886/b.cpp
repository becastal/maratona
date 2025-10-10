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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int>> v;
		for (int i = 0, a, b; i < n; i++) {
			cin >> a >> b;
			if (a > 10) continue;
			v.emplace_back(b, i+1);
		}
		sort(v.rbegin(), v.rend());
		cout << v[0].s << endl;
	}
    
    return(0);
}
