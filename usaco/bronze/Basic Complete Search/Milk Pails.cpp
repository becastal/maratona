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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("pails");

	int x, y, m; cin >> x >> y >> m;
	int res = 0;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			if (i * x + j * y <= m) {
				res = max(res, i * x + j * y);
			}
		}
	}
	cout << res << endl;

    return(0);
}
