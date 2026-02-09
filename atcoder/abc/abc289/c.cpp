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
	vector<set<int>> S(m);

	for (int i = 0, ci; i < m; i++) {
		cin >> ci;
		for (int j = 0, x; j < ci; j++) {
			cin >> x;	
			S[i].insert(x);
		}
	}

	int res = 0;
	for (int i = 1; i < (1 << m); i++) {
		vector<int> ok(n, 0);

		for (int j = 0; j < m; j++) {
			if (i & (1 << j)) {
				for (int ii = 0; ii < n; ii++) {
					ok[ii] |= S[j].count(ii+1);
				}
			}
		}

		int OK = 1;
		for (int j : ok) {
			OK &= j;
		}

		res += OK;
	}

	cout << res << endl;
    
    return(0);
}
