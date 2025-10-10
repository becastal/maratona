#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n), F(n+1, 0);
	for (int& i : A) cin >> i, F[i]++;

	int res = 0;
	for (int i = 0; i < k; i++) {
		res += !F[i];
	}
	res = max(res, F[k]);	

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

