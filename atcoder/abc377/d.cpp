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
    
    int n, m; 
    cin >> n >> m;

	vector<int> d(m+1, 1);
    for (int i = 0, li, ri; i < n; i++) {
        cin >> li >> ri;

		d[ri] = max(d[ri], li+1);
	}

	for (int i = 1; i <= m; i++) {
		d[i] = max(d[i], d[i-1]);
	}

	ll res = 0;
	for (int i = 1; i <= m; i++) {
		res += i - d[i] + 1;
	}
	cout << res << endl;
    
    return 0;
}

