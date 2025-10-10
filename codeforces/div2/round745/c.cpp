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
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m)), pre(n+1, vector<int>(m+1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			v[i][j] = c == '1';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pre[i][j] = v[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
		}
	}

	int res = INF;
	auto soma = [&](int i, int j, int ii, int jj) {
		return pre[ii][jj] - pre[i-1][jj] - pre[ii][j-1] + pre[i-1][j-1];
	};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int i1 = i+4; i1 <= n; i1++){
                int cnt = i1-i-1-soma(i+1, j, i1-1, j);
                if(cnt > res)break;

                for(int j1 = j+3; j1<=m; j1++){
                    cnt+=j1-j-1-soma(i, j+1, i, j1-1);
                    cnt+=j1-j-1-soma(i1, j+1, i1, j1-1);
 
                    cnt+=soma(i+1, j+1, i1-1, j1-1);
                    if(cnt>res)break;
                    res = min(res, cnt+i1-i-1-soma(i+1, j1, i1-1, j1));
                    cnt = i1-i-1-soma(i+1, j, i1-1, j);
                }
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
