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

int main() {
    _;
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> M(n, vector<char>(m));
    vector<vector<int>> a(n, vector<int>(m)), pre(n+1, vector<int>(m+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
            a[i][j] = (M[i][j] == '*');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = a[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    k -= 2;
    int res = 0, posi = -1, posj = -1;

	if (k == 1) {
		for (int i = 1; i < n-1 and posi == -1; i++) {
			for (int j = 1; j < m-1 and posj == -1; j++) {
				if (a[i][j]) {
					posi = i - 1;
					posj = j - 1;
					res = 1;
				}
			}
		}
	} else {
		for (int i = 2; i + k <= n - 1; i++) {
			for (int j = 2; j + k <= m - 1; j++) {
				int x1 = i, y1 = j;
				int x2 = i + k - 1, y2 = j + k - 1;

				int agr = pre[x2+1][y2+1] - pre[x1][y2+1] - pre[x2+1][y1] + pre[x1][y1];

				if (agr > res) {
					res = agr;
					posi = i - 1;
					posj = j - 1;
				}
			}
		}
	}

    if (posi == -1) {
        posi = posj = 0;
    }

    k += 2;
    for (int i = 0; i < k; i++) {
        M[posi][posj + i] = M[posi + k-1][posj + i] = '-';
        M[posi + i][posj] = M[posi + i][posj + k-1] = '|';
    }
    M[posi][posj] = M[posi][posj + k-1] = M[posi + k-1][posj] = M[posi + k-1][posj + k-1] = '+';

    cout << res << endl;
    for (auto l : M) {
        for (auto c : l) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}

