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

	vector<pair<int, int>> ev;

	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		ev.emplace_back(l, 0);
		ev.emplace_back(r, 1);
	}

	sort(ev.begin(), ev.end());
	int agr = 0, res = 0;
	for (auto [x, tp] : ev) {
		agr += tp ? -1 : 1;
		res = max(res, agr);
	}
	cout << res << endl;
    
    return(0);
}
