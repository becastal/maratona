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
	int n, k; cin >> n >> k;
	string s; cin >> s;

	for (int i = 0, j = 0; i < k; i++) {
		int k = j + 1;
		while (k < n and s[k] == 'o') {
			k++;	
		}

		if (k >= n or s[k] == '#') break;

		for (int ii = k; ii >= j + 2; ii--) {
			s[ii] = s[ii-1];
		}

		s[j] = '.';
		s[j+1] = '#';
		j++;
	}
	cout << s << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
