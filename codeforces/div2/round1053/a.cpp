#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<int> A(m);
	for (int& i : A) cin >> i;

	int cres = 1;
	for (int i = 1; i < m and cres; i++) {
		cres &= A[i] > A[i-1];
	}

	if (!cres) return cout << 1 << endl, 0;
	cout << n + 1 - A[m-1] << endl;

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

