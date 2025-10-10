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
		map<string, int> M {
			{"00", INF},
			{"01", INF},
			{"10", INF},
			{"11", INF}
		};
		for (int i = 0; i < n; i++) {
			int ni; cin >> ni;
			string s; cin >> s;
			M[s] = min(M[s], ni);
		}

		int res = min(M["11"], M["01"] + M["10"]);
		cout << (M["11"] == INF and (M["01"] == INF or M["10"] == INF) ? -1 : res) << endl;
	}
    
    return(0);
}
