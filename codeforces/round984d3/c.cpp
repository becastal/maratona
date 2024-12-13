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
	int n = (int)s.size();

	set<int> pos;
	for (int i = 0; i < n-3; i++) {
		if (s[i]=='1' and s[i+1]=='1' and s[i+2]=='0' and s[i+3]=='0') pos.insert(i);
	}

	int q; cin >> q;
	while (q--) {
		int idx; cin >> idx; idx--;
		char nc; cin >> nc;

		s[idx]=nc;
		for (int i = idx-3; i < idx+3; i++) {
			if (i >= 0 and i + 3 < n and s[i]=='1' and s[i+1]=='1' and s[i+2]=='0' and s[i+3]=='0') pos.insert(i);
			else if (pos.count(i)) pos.erase(i);
		}

		cout << (pos.empty() ? "NO" : "YES") << endl;
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
