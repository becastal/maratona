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

	int n; cin >> n;
	vector A(n, vector<int>(n));
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			A[i][j] = c - '0';
		}
	}
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };

	ll res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (auto mov : movs) {
				ll agr = 0;

				int ii = i, jj = j;
				for (int k = 0; k < n; k++) {
					agr *= 10;
					agr += A[ii][jj];
					
					ii = (ii + mov.f + n) % n;
					jj = (jj + mov.s + n) % n;
				}
				res = max(res, agr);
			}
		}
	}

	cout << res << endl;

    return(0);
}
