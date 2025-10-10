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

	int t; cin >> t;
	while (t--) {
		int n, c, d; cin >> n >> c >> d;
		vector<int> v(n * n);
		for (int& i : v) cin >> i;
		sort(v.begin(), v.end());

		vector<vector<int>> mp(n, vector<int> (n, 0));
		mp[0][0] = v[0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j + 1 < n) mp[i][j + 1] = mp[i][j] + d;
				if (i + 1 < n) mp[i + 1][j] = mp[i][j] + c;
			}
		}
		map<int, int> M;
		for (auto l : mp)  {
			for (auto c : l) {
				M[c]--;
				//cout << c << ' ';
			}
			//cout << endl;
		}

		for (int i : v)
			M[i]++;

		int res = 1;
		for (auto [i, j] : M)
			res &= !j;


		cout << (res ? "YES" : "NO") << endl;
	}
    
    return(0);
}
