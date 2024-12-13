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
	string s; cin >> s;
	int n = (int) s.size();

	vector<int> dist(26, INF);
	dist[s[0]-'a'] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			dist[s[i]-'a'] = min(dist[s[i]-'a'], dist[j] + abs(s[i]-'a'-j));
		}
	}

	for (char c : s) cout << dist[c-'a'] << ' '; cout << endl;
	
	//cout << dist[s[n-1]-'a'] << endl;
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
