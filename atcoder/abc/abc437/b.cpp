#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, k; cin >> n >> m >> k;
	
	vector<set<int>> A(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0, x; j < m; j++) {
			cin >> x;
			A[i].insert(x);
		}
	}

	vector<int> B(k);
	for (int& i : B) cin >> i;
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		int agr = 0;
		for (int j : B) {
			agr += A[i].count(j);	
		}
		res = max(res, agr);
	}
	cout << res << endl;

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

