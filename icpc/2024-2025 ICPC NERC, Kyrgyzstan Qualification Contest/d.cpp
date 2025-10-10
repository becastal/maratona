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

	int n, m, k; cin >> n >> m >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());

	int res = 0;
	for (int l = 0; l < n; ) {
		multiset<int> M;
		M.insert(v[l]);

		int bom = 1, r = l + 1;
		while (r < n and bom) {
			M.insert(v[r]);
			//for (int i : M) cout << i << ' '; cout << endl;
			bom &= M.size() <= k and (*M.rbegin() - *M.begin() <= m);
			if (bom) r++;
		}
		//printf("%d, %d\n", l, r);

		res++;
		l = r;
	}
	cout << res << endl;
    
    return(0);
}
