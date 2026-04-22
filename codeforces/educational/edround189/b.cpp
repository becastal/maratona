#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<int> A(n - 1);
	for (int i = 0; i < n - 1; i++) {
		A[i] = (S[i] != S[i + 1]);
	}

	cout << (count(all(A), 0) > 2 ? "NO" : "YES") << endl;

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

