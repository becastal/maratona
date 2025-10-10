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
	// pra toda subsequencia sem w tem que ter pelo menos uma cor de cada tipo

	int n; cin >> n;
	string s; cin >> s;

	int ok = 1;
	for (int l = 0; l < n and ok;) {
		if (s[l] == 'W') {
			l++;
			continue;
		}

		int R = 0, B = 0;
		
		int r = l;
		while (r < n and s[r] != 'W') {
			R |= s[r] == 'R';
			B |= s[r] == 'B';
			r++;
		}

		ok &= B and R;

		l = r;
	}

	cout << (ok ? "YES" : "NO") << endl;
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
