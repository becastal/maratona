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
	int n; cin >> n;
	ll c, agr = 0; cin >> c;
	string s; cin >> s;

	int res = 0;
	vector<int> cont(26, 0);
	for (int r = 0, l = 0; r < n; r++) {
		cont[s[r]-'a']++;
		if (s[r] == 'b') agr += cont[0];

		while (l < n and agr > c) {
			if (s[l] == 'a') agr -= cont[1];
			cont[s[l++]-'a']--;
		}

		res = max(res, r - l + 1);
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
