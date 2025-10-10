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

int solve() {
	vector<string> a(9);
	for (auto& i : a) cin >> i;
	
	vector<pair<int, int>> v = {
		{0, 0},
		{1, 3},
		{2, 6},
		{3, 1},
		{4, 4},
		{5, 7},
		{6, 2},
		{7, 5},
		{8, 8}
	};
	for (auto [i, j] : v) {
		a[i][j] = (a[i][j] == '9' ? '1' : a[i][j]+1);
	}

	for (auto i : a) cout << i << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
