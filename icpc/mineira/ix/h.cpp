#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
    int n, m; cin >> n >> m;

    vector A(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int ui, uj; cin >> ui >> uj; ui--, uj--;

    const array<array<int,2>,8> movs = {{
        {0,-1}, {-1,-1}, {-1,0}, {-1,1},
        {0, 1}, { 1, 1}, { 1,0}, { 1,-1}
    }};

    auto valido = [&](int i, int j) { return i >= 0 and i < n and j >= 0 and j < m; };

    for (int rep = 0; rep < n + m; rep++) {

        int den = 0;
        for (auto [di, dj] : movs) {
            int vi = ui + di, vj = uj + dj;
            if (valido(vi, vj)) den++;
        }

        if (den > 0) {
            ll q = A[ui][uj] / den;
            ll r = A[ui][uj] % den;

            for (auto [di, dj] : movs) {
                int vi = ui + di, vj = uj + dj;
                if (valido(vi, vj)) A[vi][vj] += q;
            }
            A[ui][uj] = r;

            ll mx = LLONG_MIN;
            int ui_ = ui, uj_ = uj;
            for (auto [di, dj] : movs) {
                int vi = ui + di, vj = uj + dj;
                if (!valido(vi, vj)) continue;
                if (A[vi][vj] > mx) {
                    mx = A[vi][vj];
                    ui_ = vi; uj_ = vj;
                }
            }
            ui = ui_; uj = uj_;
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res = max(res, A[i][j]);
        }
    }
    cout << res << endl;

    return 0;
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

