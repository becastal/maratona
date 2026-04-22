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
	sort(v.begin(), v.end());

	if (n == 1) return cout << 1 << endl, 0;

	int res = 360 - (v[n-1] - v[0]);
	for (int i = 0; i < n-1; i++) {
		res = max(res, v[i+1] - v[i]);
	}
	cout << 361 - res << endl;
    
    return(0);
}
