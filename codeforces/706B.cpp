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
	vector<int> v(n), pre(n+1, 0);
	for (int& i : v) cin >> i;

	sort(v.begin(), v.end());

	int m; cin >> m;
	for (int i = 0, mi; i < m; i++) {
		cin >> mi;
		cout << upper_bound(v.begin(), v.end(), mi) - v.begin() << endl;
	}
    
    return(0);
}
