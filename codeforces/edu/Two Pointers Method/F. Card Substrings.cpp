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
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;

	vector<int> cont(26, 0);	
	for (auto c : t) cont[c-'a']++;

	ll res = 0;
	for (int r = 0, l = 0; r < n; r++) {
		cont[s[r]-'a']--;

		while (cont[s[r]-'a'] < 0) {
			cont[s[l++]-'a']++;
		}

		res += r - l + 1;
	}
	cout << res << endl;

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
