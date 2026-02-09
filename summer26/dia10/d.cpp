#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, w, h, s; cin >> n >> w >> h >> s;

	vector<char> A(n);
	vector<vector<string>> B(n, vector<string>(h));

	int res = -1; string resS = "$";
	for (int k = 0; k < n; k++) {
		cin >> A[k];
		for (string& j : B[k]) {
			cin >> j;
		}
		
		for (int i = 0; i < h; i++) {
			char ult = '.';
			int agr = 0;
			for (int j = 0; j < w; j++) {
				if (B[k][i][j] != ult) agr++;
				ult = B[k][i][j];
			}
			if (ult == '#') agr++;

			if (res < agr) {
				res = agr;
				resS = A[k];
			}
		}
	}

	int c = (s + res - 1) / res;
	cout << string(c, resS[0]) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

