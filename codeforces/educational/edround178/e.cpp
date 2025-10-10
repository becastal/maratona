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

int solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<vector<int>> nxt(n+1, vector<int>(k+1, -1)), ant(n+1, vector<int>(k+1, -1));
	for (int i = n-1; i >= 0; i--) {
		nxt[i] = nxt[i+1];
		nxt[i][s[i]-'a'] = i;
	}

	for (int i = 0; i <= n; i++) {
		if (i) ant[i] = ant[i-1];
		if (i < n) ant[i][s[i]-'a'] = i;
	}

	vector<int> d(n+1, INF);
	d[n] = 1;
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < k; j++) {
			if (nxt[i][j] == -1) d[i] = 1;
			else d[i] = min(d[i], d[nxt[i][j] + 1] + 1);
		}
	}

	int qr; cin >> qr;
	while (qr--) {
		string t; cin >> t;
		int r = 0;
		for (int l = 0; l < (int)t.size(); l++) {
			if (nxt[r][t[l]-'a'] == -1) {
				r = -1;
				break;
			};
			r = nxt[r][t[l]-'a'] + 1;
		}

		cout << (r == -1 ? 0 : d[r]) << endl;
	}

	return(0);
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
