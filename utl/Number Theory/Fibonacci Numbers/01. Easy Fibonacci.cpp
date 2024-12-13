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

	const int mod = 1e8+7;
	const int maxn = (int)5e5+10;
	int f[maxn];

	f[0] = 0, f[1] = 1;
	for (int i = 2; i < maxn; i++) {
		f[i] = (f[i-2] + f[i-1]) % mod;	
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << f[n] << endl;
	}
    
    return(0);
}
