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
	vector<pair<int, int>> v(n);

	for (auto& [l, r] : v) {
		cin >> l >> r;
	}

	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.s < b.s;
	});

	int ult = 0, res = 0;
	for (auto [l, r] : v) {
		if (l >= ult) {
			res ++;
			ult = r;
		}
	}
	cout << res << endl;

    return(0);
}
