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

	map<int, int> M;
	ll res = 0;
	for (int r = 0, l = 0; r < n; r++) {
		M[v[r]]++;

		while (M.size() > k) {
			if (--M[v[l]] == 0) {
				M.erase(v[l]);	
			}
			l++;
		}
		
		res += r - l + 1;
	}
	cout << res << endl;
    
    return(0);
}
