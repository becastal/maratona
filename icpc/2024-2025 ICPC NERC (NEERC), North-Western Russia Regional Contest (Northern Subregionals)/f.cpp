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

	set<int> S;
	for (int i = 0; i < n; i++) {
		int h; cin >> h;
		char c; cin >> c;
		int m; cin >> m;

		m += h * 60;
		S.insert(m);
	}

	int res = 3;
	for (int i : S) {
		int agr = 3;
		for (int j = i; j <= i + 10; j++) {
			agr -= S.count(j);
		}
		res = min(res, max(agr, 0));
	}
	cout << res << endl;

    return(0);
}
