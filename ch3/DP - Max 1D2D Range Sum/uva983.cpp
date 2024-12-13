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

int n, m;
void solve() {
    vector<vector<int>> A(n, vector<int>(n)), B(n-m+1, vector<int>(n-m+1)), pre(n+1, vector<int>(n+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] = A[i-1][j-1] + pre[i-1][j] + pre[i][j-1]-pre[i-1][j-1];
        }
    }

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            B[i][j] = pre[i + m][j + m] - pre[i + m][j] - pre[i][j + m] + pre[i][j];
        }
    }

	int total = 0;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			cout << B[i][j] << endl;
			total += B[i][j];
		}
	}

	cout << total << endl;
}

int main() {
    _;
    int i = 0;

    while (cin >> n >> m) {
        if (i++) cout << endl;
        solve();
    }

    return 0;
}

