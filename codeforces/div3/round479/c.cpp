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

	if (k == n) return cout << v.back() << endl, 0;
	if (k == 0) return cout << (v[0] > 1 ? 1 : -1) << endl, 0;

	if (v[k] == v[k-1]) {
		cout << -1 << endl;
	} else {
		cout << v[k-1] << endl;
	}
    
    return(0);
}
