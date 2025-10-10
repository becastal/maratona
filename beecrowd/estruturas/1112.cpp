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

const int MAX = 1010;
namespace bit2d {
	int fen[MAX][MAX];
	int n, m;

	int pre(int x, int y) {
	    int res = 0;
	    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
	        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
	            res += fen[i][j];
	        }
	    }
	    return res;
	}

	int query(int x1, int y1, int x2, int y2) {
	    return pre(x2, y2) - pre(x1 - 1, y2) - pre(x2, y1 - 1) + pre(x1 - 1, y1 - 1);
	}

	void update(int x, int y, int val) {
	    for (int i = x; i < n; i = i | (i + 1)) {
	        for (int j = y; j < m; j = j | (j + 1)) {
	            fen[i][j] += val;
	        }
	    }
	}
}


int main()
{
    _;

	int n, m, p;
	while (cin >> n >> m >> p and n) {
		bit2d::n = n, bit2d::m = m;
		memset(bit2d::fen, 0, sizeof(bit2d::fen));

		int q; cin >> q;
		while (q--) {
			char c; cin >> c;

			if (c == 'A') {
				int ni, x, y;
				cin >> ni >> x >> y;
				bit2d::update(x, y, ni);
			} else {
				int x, y, z, w;
				cin >> x >> y >> z >> w;

				int xi = min(x, z), xj = max(x, z);
				int yi = min(y, w), yj = max(y, w);
				cout << bit2d::query(xi, yi, xj, yj) * p << endl;
			}
		}
		cout << endl;
	}
    
    return(0);
}

