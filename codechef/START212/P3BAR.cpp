#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	da pra fazer nlogn bem facil
*/

int solve() {
	int n; cin >> n;

	vector<int> P(n);
	for (int& i : P) cin >> i;

	int res = 0;
	for (int i = 0; i < n; i++) {
		int C[2] = {0, 0};
		for (int j = 0; j < n; j++) if (i != j) {
			C[j > i] += P[j] < P[i];
		}
		res += min(C[0], C[1]);
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

