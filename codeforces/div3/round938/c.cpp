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

	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		vector<int> v(n);
		for (int& i : v) cin >> i;

		int res = 0;
		for (int l = 0, r = n - 1; l <= r and k > 0;) {
			if (l == r) {
				if (k >= v[l]) res++;	
				k = 0;
				continue;
			}
			int m = min(v[l], v[r]);
			if (k >= 2 * m) { 
				v[r] -= m;
				v[l] -= m;
				k -= 2 * m;
			} else { 
				v[r] -= k / 2;
				v[l] -= k / 2 + (k & 1);
				k = 0;
			}
			
			if (!v[r]) r--, res++;
			if (!v[l]) l++, res++;
		}
		cout << res << endl;
	}
    
    return(0);
}
