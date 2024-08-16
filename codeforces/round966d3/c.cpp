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
	vector<int> v(n);
	for (int& i : v) cin >> i;

	map<int, int> mp;
	vector<int> pad(n);
	for (int i = 0; i < n; i++) {
		if (mp.count(v[i])) {
			pad[i] = mp[v[i]];	
		} else {
			pad[i] = i;
			mp[v[i]] = i;
		}
	}
	//for (int i : pad) cout << i << ' ';
	//cout << endl;

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (s.size() != n) { cout << "no" << endl; continue; }
		vector<int> c(26, -1);

		bool ok = 1;
		for (int j = 0; j < (int)s.size() and ok; j++) {
			if (c[s[j] - 'a'] == -1) {
				c[s[j] - 'a'] = j;
			} 

			ok &= c[s[j] - 'a'] == pad[j];
		}
		cout << (ok ? "yes" : "no") << endl;
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
