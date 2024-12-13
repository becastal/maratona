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
	
	vector<int> v(26, 0);
	for (char c : s) {
		if (v[c-'a']) {
			n -= 2;
			fill(v.begin(), v.end(), 0);
		} else v[c-'a'] = 1;
	}
	cout << n << endl;
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
