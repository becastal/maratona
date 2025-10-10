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
	vector<vector<int>> v(2);

	for (int i = 0, x; i < n; i++) {
		cin >> x; v[x&1].push_back(x);
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].rbegin(), v[1].rend());

	for (int i = 0; i < 2; i++) {
		for (int j : v[i]) cout << j << endl;
	}
    
    return(0);
}
