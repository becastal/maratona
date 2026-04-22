#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 2000;
int A[MAX + 10][MAX + 10];
int B[MAX + 10][MAX + 10];

int solve() {
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	int n; cin >> n;

	vector<array<int, 4>> V(n);

	for (auto& [x1, x2, y1, y2] : V) {
		cin >> x1 >> x2 >> y1 >> y2;
		A[x1][y1]++;
		A[x2 + 1][y1]--;
		A[x1][y2 + 1]--;
		A[x2 + 1][y2 + 1]++;
	}

	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; j <= MAX; j++) {
			A[i][j] += - A[i-1][j-1] + A[i-1][j] + A[i][j-1];
		}
	}

	int zeros = 0;
	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; j <= MAX; j++) {
			B[i][j] = (A[i][j] == 1) + B[i-1][j] + B[i][j-1] - B[i-1][j-1];
			zeros += (A[i][j] == 0);
		}
	}

	for (auto& [x1, x2, y1, y2] : V) {
		int uns = B[x2][y2] - B[x2][y1-1] - B[x1-1][y2] + B[x1-1][y1-1];
		cout << zeros + uns << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

