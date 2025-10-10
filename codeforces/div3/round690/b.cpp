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
	string s; cin >> s;
	string t = "2020";


	if (s.substr(0, 4) == t or s.substr(n-4, 4) == t) return cout << "YES" << endl, 0;
	for (int i = 1; i <= 3; i++) {
		string a = s.substr(0, i), b = s.substr(n-(4-i), 4-i);
		if (a + b == t) return cout << "YES" << endl, 0;
	}
	cout << "NO" << endl;

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
