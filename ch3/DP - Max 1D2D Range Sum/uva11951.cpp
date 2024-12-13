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

void solve() {
	int n, m, k; cin >> n >> m >> k;
	ll total = 0;
	
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];	
			total ++ a[i][j]
			if (j) a[i][j] += a[i][j-1];
		}
	}

    ll res = ;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            ll subRec = 0;
            for (int ii = 0; ii < n; ii++) {
                ll colSum = a[ii][j] - (i > 0 ? a[ii][i - 1] : 0LL);
                subRec = max(subRec + colSum, 0LL);
				if (subRec > k) subRec = 0LL;
                res = max(res, subRec);
            }
        }
    }

	cout << res << endl;
}

int main()
{
    _;

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ' ';
		solve();
	}
    
    return(0);
}
