#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);
	for (auto& i : A) cin >> i;
	
	int x, y; cin >> x >> y;
	vector<string> B(x);
	for (auto& i : B) cin >> i;	

	auto match = [x](vector<string>& a, int cola, int inia,
					vector<string>& b, int colb, int inib) {
		for (int i = 0; i < x; i++) {
			if (a[i + inia][cola] != b[i + inib][colb]) return 0;
		}
		return 1;
	};

	vector<int> P(y);
	for (int i = 1, j = 0; i < y; i++) {
		while (j and !match(B, j, 0, B, i, 0)) j = P[j-1];
		P[i] = (j += match(B, j, 0, B, i, 0));
	}

	int res = 0;
	for (int lin = 0; lin + x <= n; lin++) {
		for (int i = 0, j = 0; i < m; i++) {
			while (j and !match(B, j, 0, A, i, lin)) j = P[j-1];
			j += match(B, j, 0, A, i, lin);
			if (j == y) res++, j = P[j-1];
		}
	}
	cout << res  << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

