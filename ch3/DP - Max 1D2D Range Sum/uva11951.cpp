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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> a(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (i) a[i][j] += a[i-1][j];
		}
	}

	int area = 0, menor_c = INF;
	for (int i = 0; i < n; i++) {
		for (int ii = i; ii < n; ii++) {
			int j = 0, tmp = 0;

			for (int jj = 0; jj < m; jj++) {
				tmp += a[ii][jj] - (i ? a[i-1][jj] : 0);

				while (j <= jj and tmp > k) {
					tmp -= a[ii][j] - (i ? a[i-1][j] : 0);
					j++;
				}

				int areai = (jj-j+1)*(ii-i+1);

				if (areai > area or (areai == area and tmp < menor_c)) {
					area = areai;
					menor_c = tmp;
				}
			}
		}
	}

	cout << area << ' ' << menor_c << endl;
}

int main()
{
    _;

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}

    return 0;
}

