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
	vector<vector<int>> v(n, vector<int>(n));
	for (auto& i : v) for (auto& j : i) cin >> j;

	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i] |= v[i][j];
		}
	}

	for (int i : a) cout << i << ' '; cout << endl;
    
    return(0);
}
