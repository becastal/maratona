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

	int res = 0;
	for (int l = 0; l < n;) {
		int r = l+1;	
		while (r < n and v[r] >= v[r-1]) r++;

		res = max(res, r - l);
		l = r;
	}

	cout << res << endl;
    
    return(0);
}
