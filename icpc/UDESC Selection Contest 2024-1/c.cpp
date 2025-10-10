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
	string s; cin >> s;
	vector<vector<int>> ok(26, vector<int>(26, 0));

	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (auto& [i, j] : a) {
		char ii, jj; cin >> ii >> jj;
		i = ii - 'a', j = jj - 'a';
		ok[i][j] = 1;
	}

	for (int i = 1; i < (int)s.size(); i++) {
		if (!ok[s[i-1]-'a'][s[i]-'a']) return cout << "NAO" << endl, 0;
	}
	cout << "SIM" << endl;

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
