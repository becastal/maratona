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
	int n, b; cin >> n >> b;
	vector<vector<int>> a(n, vector<int>(n, 1));
	for (int i = 0; i < b; i++) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >>c2; r1--, r2--, c1--, c2--;
		
		for (int ii = r1; ii <= r2; ii++) {
			for (int jj = c1; jj <= c2; jj++) {
				a[ii][jj] = -100;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			a[i][j] += a[i][j-1];
		}
	}

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll subRec = 0;
            for (int ii = 0; ii < n; ii++) {
                ll colSum = a[ii][j] - (i > 0 ? a[ii][i - 1] : 0);
                subRec = max(subRec + colSum, 0LL);
                res = max(res, subRec);
            }
        }
    }

	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
