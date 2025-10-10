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
	string a, s; cin >> a >> s;
	int n = (int)a.size(), m = (int)s.size();

	string b = "";
	int l, r;
	for (l = n-1, r = m-1; l >= 0; l--) {

		if (s[r] >= a[l]) {
			b.push_back('0' + s[r] - a[l]);	
			r--;
			continue;
		}

		if (r <= 0) return cout << -1 << endl, 0;
		int ds = (s[r-1] - '0') * 10 + (s[r] - '0');
		int x = ds - (a[l] - '0');
		if (x < 0 or x > 9) return cout << -1 << endl, 0;
		b.push_back('0' + x);
		r -= 2;
	}

	while (r >= 0) b.push_back(s[r--]);
	while (b.size() and b.back() == '0') b.pop_back();

	if (b.empty()) return cout << -1 << endl, 0;

	reverse(b.begin(), b.end());
	cout << b << endl;

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
