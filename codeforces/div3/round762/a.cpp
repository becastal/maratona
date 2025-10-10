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
	int n = (int)s.size();

	if (n & 1) return cout << "NO" << endl, 0;

	for (int l = 0, r = n/2; l < n/2; l++, r++) {
		if (s[l] != s[r]) return cout << "NO" << endl, 0;
	}
	cout << "YES" << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
