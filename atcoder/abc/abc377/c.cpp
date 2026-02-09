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

	int n, m; cin >> n >> m;

	set<pair<int, int>> S;
	vector<pair<int, int>> movs = {{+2,+1}, {+1,+2}, {-1,+2}, {-2,+1}, {-2,-1}, {-1,-2}, {+1,-2}, {+2,-1}};
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		S.emplace(x, y);
		for (auto mov : movs) {
			int xi = x + mov.f, yi = y + mov.s;

			if (xi >= 1 and yi >= 1 and xi <= n and yi <= n) {
				S.emplace(xi, yi);
			}
		}
	}

	cout << (ll)n * (ll)n - S.size() << endl;
    
    return(0);
}
