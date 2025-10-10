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

	int n, W; cin >> n >> W;
	vector<int> w(n), v(n);
	vector<vector<int>> M(4);

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		M[abs(w[i] - w[0])].push_back(v[i]);
	}

	vector<vector<int>> pre(4);
	for (int i = 0; i < 4; i++) {
		sort(M[i].rbegin(), M[i].rend());
		pre[i] = vector<int>(M[i].size() + 1, 0);

		for (int j = 1; j <= M[i].size(); j++) {
			pre[i][j] = pre[i][j-1] + M[i][j-1];	
		}
	}

	ll res = 0;
	for (int i = 0; i <= M[0].size(); i++) {
		for (int j = 0; j <= M[1].size(); j++) {
			for (int ii = 0; ii <= M[2].size(); ii++) {
				for (int jj = 0; jj <= M[3].size(); jj++) {
					ll w_ = 0, v_ = 0;
					vector<int> bobo = {i, j, ii, jj};
					for (int iii = 0; iii < 4 and w_ <= W; iii++) {
						w_ += (ll)(w[0] + iii) * bobo[iii];
						v_ += pre[iii][bobo[iii]];
					}
					if (w_ > W) continue;	
					res = max(res, v_);
				}
			}
		}
	}
	cout << res << endl;
    
    return(0);
}
