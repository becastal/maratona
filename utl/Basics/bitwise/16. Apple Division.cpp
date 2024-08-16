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
	vector<ll> v(n);
	for (ll& vi : v)
		cin >> vi;
	
	function<ll(int, ll, ll)> f = [&] (int i, ll a, ll b) {
		if (i == n) return abs(a - b);
		return min(f(i + 1, a + v[i], b), f(i + 1, a, b + v[i]));
	};
 
 	cout << f(0, 0, 0) << endl;
    
    return(0);
}
