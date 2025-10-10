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

	int n; cin >> n;
	while (n--) {
		ll x; cin >> x;
		int res = 0;

		string s = bitset<50>(x).to_string();
		for (int l = 0; l < 64;) {
			if (!(x & (1LL << l))) {
				l++;
				continue;
			}

			int r = l + 1;
			while (r < 64 and x & (1LL << r)) {
				r++;
			}

			res = max(res, r - l);
			l = r;
		}
		cout << res << endl;
	}
    
    return(0);
}
