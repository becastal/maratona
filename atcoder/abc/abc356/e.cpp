#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 1e6+10;
int P[MAX];

int solve() {
	int n; cin >> n;
	map<int, int> M;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		M[a]++;
		P[a]++;
	}
	for (int i = 1; i < MAX; i++) {
		P[i] += P[i-1];
	}

	int res = 0;
	for (auto [a, b] : M) {
		for (int i = a, j = 1; i < MAX; i += a, j++) {
			int r = min(i + a - 1, MAX - 1);
			int cont = P[r] - P[i - 1];

			if (j == 1) {
				int soma = ((cont - b) + (cont - 1)) * b / 2;
				res += j * soma;
			} else {
				res += j * b * cont;
			}
		}
	}
	cout << res << endl;

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

