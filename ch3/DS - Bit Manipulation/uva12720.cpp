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

const int mod = 1e9+7;

void solve() {
	string s, a = ""; cin >> s;
	int n = (int)s.size();

	int l, r;
	if (n&1) {
		a.push_back(s[n/2]);
		l = n/2-1, r=n/2+1;
	} else {
		l = n/2-1, r=n/2;
	}
	
	for (int i = 0; i < n/2; i++) {
		a.push_back(max(s[l], s[r]));	
		a.push_back(min(s[l], s[r]));	
		l--, r++;
	}
	//dbg(a);
	reverse(a.begin(), a.end());

	ll p2 = 1, res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') res = (res + p2) % mod;
		p2 = (p2 * 2) % mod;
	}
	cout << res << endl;
}

int main()
{
    _;

	int t, cas = 0; cin >> t;
	while (t--) {
		cout << "Case #" << ++cas << ": ";
		solve();
	}
    
    return(0);
}
