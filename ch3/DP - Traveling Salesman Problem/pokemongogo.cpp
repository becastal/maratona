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

    int n; cin >> n; n++;
    vector<tuple<int, int, string>> V(n);
	map<string, int> M;

    V[0] = {0, 0, "$"};
	M["$"] = 0;	
    for (int i = 1; i < n; i++) {
        auto& [x, y, s] = V[i];
        cin >> x >> y >> s;
		if (!M.count(s)) {
			M[s] = (int) M.size();
		}
	}

    vector<vector<int>> d(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            auto [xi, yi, si] = V[i]; 
            auto [xj, yj, sj] = V[j]; 
            d[i][j] = d[j][i] = abs(xi - xj) + abs(yi - yj);
        }
    }

	int N = (int)M.size();
    vector<vector<int>> dp((1 << N), vector<int>(n, INF));
    dp[1][0] = 0;

    for (int i = 0; i < (1 << N); i++) {
        for (int u = 0; u < n; u++) {
            if (!(i & (1 << (M[get<2>(V[u])])))) continue;

            for (int v = 0; v < n; v++) {
                if (i & (1 << (M[get<2>(V[v])]))) continue; 

                int ni = i | (1 << M[get<2>(V[v])]);
                dp[ni][v] = min(dp[ni][v], dp[i][u] + d[u][v]);
            }
        }
    }

    int res = INF;
    for (int i = 1; i < n; i++) {
        res = min(res, dp[(1 << N) - 1][i] + d[i][0]);
    }
    cout << res << endl;
    
    return(0);
}
