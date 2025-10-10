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
	setIO("mowing");

	int n; cin >> n;
	pair<int, int> pos = {0, 0};
	map<pair<int, int>, int> M;

	M[pos] = 0;
	int res = INF, cont = 0;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		int x; cin >> x;

		for (int j = 0; j < x; j++) {
			cont++;
			if (c == 'N') pos.s++;
			if (c == 'S') pos.s--;
			if (c == 'W') pos.f++;
			if (c == 'E') pos.f--;

			if (M.count(pos)) {
				res = min(res, cont - M[pos]);
			}
			M[pos] = cont;
		}
	}
	cout << (res == INF ? -1 : res) << endl;

    return(0);
}
