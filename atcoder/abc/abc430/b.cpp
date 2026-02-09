#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);

	for (auto& i : A) cin >> i;

	set<vector<string>> S;

	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			vector<string> B(m);
			for (int k = 0; k < m; k++) {
				B[k] = A[i + k].substr(j, m);
			}
			S.insert(B);
		}
	}
	cout << S.size() << endl;

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

