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

	int n, a, b, k; cin >> n >> a >> b >> k;
	vector<int> v(n), c(n);
	for (int& i : v) cin >> i;

	for (int i = 0; i < n; i++) {
		int hi = v[i] - ((v[i]-1) / (a+b)) * (a+b);
		c[i] = max(0, (hi + a - 1) / a - 1);
	}
	
	sort(c.begin(), c.end());
	int res = 0;
	for (int i : c) {
		if (k - i < 0) break;	
		k -= i;
		res++;
	}
	cout << res << endl;
    
    return(0);
}
