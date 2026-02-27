#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, d; cin >> n >> d;
	
	vector<int> A(n), B(n);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	queue<array<int, 2>> Q;

	for (int i = 0; i < n; i++) {
		Q.push({i, A[i]});

		int b = B[i];
		while (b and Q.size()) {
			int mn = min(b, Q.front()[1]);
			b -= mn;
			Q.front()[1] -= mn;
			if (Q.front()[1] == 0) {
				Q.pop();
			}
		}
		assert(!b);

		while (Q.size() and i - Q.front()[0] >= d) {
			Q.pop();	
		}
	}

	int res = 0;
	while (Q.size()) {
		res += Q.front()[1];
		Q.pop();
	}
	cout << res << endl;

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

