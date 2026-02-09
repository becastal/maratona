#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n+1, 0), L(n);
	for (int& i : L) cin >> i;

	A[0] = A[n] = 1;
	for (int p = n-1; p >= 0 and !L[p]; p--) {
		A[p] = 1;	
	}
	for (int p = 0; p < n and !L[p]; p++) {
		A[p+1] = 1;
	}

	cout << n + 1 - accumulate(all(A), 0) << endl;

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

