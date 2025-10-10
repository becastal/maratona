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
	string S; cin >> S;
	int n = (int)S.size();

	vector<vector<int>> prox(n+1, vector<int>(98, INF));

	for (int i = n-1; i >= 0; i--) {
		prox[i] = prox[i+1];
		prox[i][S[i]-'A'] = i;
	}

	int q; cin >> q;
	while (q--) {
		string t; cin >> t;
		int m = (int)t.size(), ok = 1;

		for (int i = 0, pos = 0; i < m and ok; i++) {
			pos = prox[pos][t[i] - 'A'];
			ok &= pos != INF;
			pos++;
		}

		cout << (ok ? "Yes" : "No") << endl;
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
