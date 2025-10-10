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
	int n, q; cin >> n >> q;	

	string a, b; cin >> a >> b;

	vector<vector<int>> sa(n+1, vector<int>(26, 0)), sb(n+1, vector<int>(26, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			sa[i][j] = sa[i-1][j];
			sb[i][j] = sb[i-1][j];
		}
		sa[i][a[i-1]-'a']++;
		sb[i][b[i-1]-'a']++;
	}

	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--;
		vector<int> sai = sa[r], sbi = sb[r];

		for (int i = 0; i < 26; i++) {
			sai[i] -= sa[l][i];
			sbi[i] -= sb[l][i];
		}

		int res = 0;
		for (int i = 0; i < 26; i++) {
			res += abs(sai[i] - sbi[i]);
		}
		cout << res / 2 << endl;
	}
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
