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
 
	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());
 
	int res = 0;
	for (int l = 0, r = n-1; l <= r;) {
		if (l == r) {
			res++;
			break;
		}
 
		if (v[r] + v[l] <= x) {
			res++;
			l++, r--;
		} else {
			res++;
			r--;
		}
	}
	cout << res << endl;
    
    return(0);
}
