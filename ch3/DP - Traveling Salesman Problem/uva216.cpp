#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int, int> ii;

void solve(int n) {
    vector<ii> p(n);
    for (auto& [a, b] : p) {
        cin >> a >> b;
    }

    vector<vector<double>> d(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = sqrt(pow(p[i].f - p[j].f, 2) + pow(p[i].s - p[j].s, 2)) + 16.0;
        }
    }

    vector<vector<double>> DP((1 << n), vector<double>(n, 9e9));
    vector<vector<ii>> PAI((1 << n), vector<ii>(n, {-1, -1}));
	double RES = 9e9;

	for (int in = 0; in < n; in++) {
		vector<vector<double>> dp((1 << n), vector<double>(n, 9e9));
		vector<vector<ii>> pai((1 << n), vector<ii>(n, {-1, -1}));
		dp[(1 << in)][in] = 0.0;

		for (int i = 1; i < (1 << n); i++) {
			for (int u = 0; u < n; u++) {
				if (!(i & (1 << u))) continue;

				for (int v = 0; v < n; v++) {
					if (i & (1 << v)) continue;

					int ni = i | (1 << v);
					if (dp[i][u] + d[u][v] < dp[ni][v]) {
						pai[ni][v] = {i, u};	
						dp[ni][v] = dp[i][u] + d[u][v];
					}
				}
			}
		}

		double res_i = *min_element(dp[(1 << n)-1].begin(), dp[(1 << n)-1].end());
		if (res_i < RES) {
			RES = res_i;
			DP = move(dp);
			PAI = move(pai);
		}
	}

	vector<ii> cam;
	for (int ni = (1 << n)-1, i = min_element(DP[ni].begin(), DP[ni].end()) - DP[ni].begin(), ult = -1; ni != -1; ult = i, tie(ni, i) = PAI[ni][i]) {
		if (ult == -1) continue;
		cam.emplace_back(i, ult);
	}
	reverse(cam.begin(), cam.end());

    cout << fixed << setprecision(2);
	for (auto [a, b] : cam) {
		cout << "Cable requirement to connect (" << p[a].f << "," << p[a].s << ") to (" << p[b].f << "," << p[b].s << ") is " << d[a][b] << " feet." << endl;
	}

    double tot = *min_element(DP[(1 << n)-1].begin(), DP[(1 << n)-1].end());
    cout << "Number of feet of cable required is " << tot << "." << endl;
}

int main() {
    _;

    int n, t = 1;
    while (cin >> n && n) {
        cout << "**********************************************************\n";
        cout << "Network #" << t++ << endl;
        solve(n);
    }

    return 0;
}

