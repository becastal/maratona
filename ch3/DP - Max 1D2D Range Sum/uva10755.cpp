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
    int a, b, c;
    cin >> a >> b >> c;
    vector<vector<vector<ll>>> A(a, vector<vector<ll>>(b, vector<ll>(c)));

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                cin >> A[i][j][k];
                if (j > 0) A[i][j][k] += A[i][j - 1][k];
            }
        }
    }

    vector<ll> C(c, 0);
    for (int k = 0; k < c; k++) {
        for (int i = 0; i < b; i++) {
            for (int j = i; j < b; j++) {
                ll subRec = 0;
                for (int ii = 0; ii < a; ii++) {
                    ll currSum = A[ii][j][k] - (i > 0 ? A[ii][i - 1][k] : 0LL);
                    subRec = max(subRec + currSum, 0LL);
                    C[k] = max(C[k], subRec);
                }
            }
        }
    }

    ll res = -LINF, agr = 0;
    for (int i = 0; i < c; i++) {
        agr = max(agr + C[i], 0LL);
        res = max(res, agr);
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
