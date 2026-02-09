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

int main()
{
    _;

	int n, q; cin >> n >> q;
	int res = 0;
	string s; cin >> s;

	for (int i = 0; i < n - 2; i++) {
		res += (s[i] == 'A' and s[i+1] == 'B' and s[i+2] == 'C');
	}

	for (int i = 0; i < q; i++) {
		int x; cin >> x; x--;
		char c; cin >> c;

		for (int j = 0; j < 3; j++) {
			int ii = x - j;
			if (ii < 0 or ii + 2 >= n) continue;
			res -= (s[ii] == 'A' and s[ii+1] == 'B' and s[ii+2] == 'C');
		}

		s[x] = c;
		for (int j = 0; j < 3; j++) {
			int ii = x - j;
			if (ii < 0 or ii + 2 >= n) continue;
			res += (s[ii] == 'A' and s[ii+1] == 'B' and s[ii+2] == 'C');
		}
		cout << res << endl;
	}
    
    return(0);
}
