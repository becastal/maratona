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
	int n; cin >> n;

	vector<vector<int>> cont(26, vector<int>(26, 0));
	vector<string> v(n);

	ll res = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 26; k++) {
				if (v[i][j] == k+'a') continue;				

				string s = v[i]; s[j] = k+'a';
				res += cont[s[0]-'a'][s[1]-'a'];
			}
		}
		cont[v[i][0]-'a'][v[i][1]-'a']++;
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
