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

	int n, m; cin >> n >> m;
	vector<int> v(n+1, 0);

	for (int i = 0; i < m; i++) {
		int ai; char bi;
		cin >> ai >> bi;

		cout << (!v[ai] and bi == 'M' ? "Yes" : "No") << endl;
		v[ai] |= (bi == 'M');
	}
    
    return(0);
}
