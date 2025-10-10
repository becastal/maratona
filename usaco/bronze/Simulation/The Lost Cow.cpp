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
	setIO("lostcow");

	int x, y, res = 0; cin >> x >> y;
	int xi = x;

	for (int dir = 1, i = 1;; dir ^= 1, i <<= 1) {
		int x_ = xi + (dir ? 1 : -1) * i;

		if ((x <= y and y <= x_) or (x >= y and y >= x_)) {
			res += abs(y - x);
			break;
		}

		res += abs(x_ - x);
		x = x_;
	}
	cout << res<< endl;

    return(0);
}
