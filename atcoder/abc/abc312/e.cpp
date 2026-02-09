#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int C[110][110][110];

int solve() {
	int n; cin >> n;
	memset(C, 0, sizeof(C));

	for (int i = 0, xa, xb, ya, yb, za, zb; i < n; i++) {
		cin >> xa >> ya >> za >> xb >> yb >> zb;
		for (int a = xa; a < xb; a++) {
			for (int b = ya; b < yb; b++) {
				for (int c = za; c < zb; c++) {
					C[a][b][c] = i + 1;	
				}
			}
		}
	}

	vector<set<int>> R(n+1);
	auto add = [&](int a, int b) {
		R[a].insert(b);
		R[b].insert(a);
	};

	for (int a = 0; a <= 100; a++) {
		for (int b = 0; b <= 100; b++) {
			for (int c = 0; c <= 100; c++) if (C[a][b][c]) {
				if (C[a+1][b][c] and C[a+1][b][c] != C[a][b][c]) {
					add(C[a][b][c], C[a+1][b][c]);
				}
				if (C[a][b+1][c] and C[a][b+1][c] != C[a][b][c]) {
					add(C[a][b][c], C[a][b+1][c]);
				}
				if (C[a][b][c+1] and C[a][b][c+1] != C[a][b][c]) {
					add(C[a][b][c], C[a][b][c+1]);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << R[i+1].size() << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

