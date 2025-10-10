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

	int n, c, k;
	while (cin >> n >> c >> k and n) {
		vector<int> v(k+1, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0, x; j < c; j++) {
				cin >> x; v[x]++;
			}
		}

		int mn = INF;
		for (int i = 1; i <= k; i++) {
			mn = min(mn, v[i]);
		}
		
		vector<int> res;
		for (int i = 1; i <= k; i++) {
			if (v[i] == mn) {
				res.push_back(i);
			}
		}

		int m = (int)res.size();
		for (int i = 0; i < m; i++) {
			cout << res[i] << " \n"[i==m-1];
		}
	}
    
    return(0);
}
