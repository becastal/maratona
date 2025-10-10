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

int main()
{
    _;

	int n, k;
	while (cin >> n >> k) {
		vector<int> v(n);
		for (int& i : v) cin >> i;

		sort(v.rbegin(), v.rend());
		int res = 0;
		for (int i = 0; i < k; i++) {
			res = (res + v[i]) % mod;
		}
		cout << res << endl;
	}
    
    return(0);
}
