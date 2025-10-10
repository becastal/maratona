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
	vector<int> v(n);
	for (int& i : v) cin >> i;

	ll res = 0;
	for (int i = 1; i < n; i++) {
		res += upper_bound(v.begin(), v.begin() + i, v[i]/2) - v.begin();	
	}
	cout << res << endl;
    
    return(0);
}
