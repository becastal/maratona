#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector<string> C(n);
	
	vector<string> D(m);
	vector<int> P(m+1);

	for (auto& i : C) cin >> i;
	for (auto& i : D) cin >> i;
	for (auto& i : P) cin >> i;

	map<string, int> M;
	for (int i = 0; i < m; i++) {
		M[D[i]] = P[i+1];
	}

	int res = 0;
	for (auto& i : C) {
		res += (M.count(i) ? M[i] : P[0]);
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

