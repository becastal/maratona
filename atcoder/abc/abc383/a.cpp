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

	int n, res = 0; cin >> n;
	vector<int> t(n), v(n);

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> v[i];
		if (i) {
			res = max(0, res - (t[i] - t[i-1]));
		}
		res += v[i];
	}

	cout << res << endl;
    
    return(0);
}
