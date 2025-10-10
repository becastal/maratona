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

	string s;

	getline(cin, s); stringstream ss(s);
	int N; ss >> N;

	map<string, pair<double, double>> M;	
	for (int i = 0; i < N; i++) {
		getline(cin, s); stringstream ss(s);
		string si;
		double x, y;
		ss >> si >> x >> y;
		M[si] = pair<double, double>(x, y);
	}

	auto solve = [&M] (vector<string>& v) {
		int n = v.size();

		vector<vector<double>> d(n, vector<double>(n, 0));

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				d[i][j] = d[j][i] = sqrt((M[v[i]].f - M[v[j]].f) * (M[v[i]].f - M[v[j]].f) + 
				                         (M[v[i]].s - M[v[j]].s) * (M[v[i]].s - M[v[j]].s));
			}
		}

		vector<vector<double>> dp((1 << n), vector<double>(n, 9e9));
		vector<vector<pair<int, int>>> pai((1 << n), vector<pair<int, int>>(n, {-1, -1}));
		dp[1][0] = 0;

		for (int i = 0; i < (1 << n); i++) {
			for (int u = 0; u < n; u++) {
				if (!(i & (1 << u))) continue;

				for (int v = 0; v < n; v++) {
					if (i & (1 << v)) continue;

					int ni = i | (1 << v);
					if (dp[i][u] + d[u][v] < dp[ni][v]) {
						dp[ni][v] = dp[i][u] + d[u][v];
						pai[ni][v] = {i, u};
					}
				}
			}
		}

		vector<string> res;
		for (int i = (1 << n) - 1, ii = n-1; i != -1; tie(i, ii) = pai[i][ii]) {
			res.push_back(v[ii]);
		}
		reverse(res.begin(), res.end());

		for (int i = 1; i < (int)res.size()-1; i++) {
			cout << res[i] << ' ';
		}
		cout << endl;
	};

	while (getline(cin, s)) {
		stringstream ss(s);
		vector<string> v = {"work"};

		string si;
		while (ss >> si) {
			v.push_back(si);
		}

		v.push_back("home");
		solve(v);
	}
    
    return(0);
}
