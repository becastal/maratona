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

	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());

	int res = INF;
	for (int i = 0; i <= k; i++) {
		res = min(res, v[i+n-k-1] - v[i]);
	}
    
	cout << res << endl;

    return(0);
}
