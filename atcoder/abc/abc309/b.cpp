#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	auto B = A;
	for (int j = 1; j < n; j++) {
		B[0][j] = A[0][j-1];
	}
	for (int i = 1; i < n; i++) {
		B[i][n-1] = A[i-1][n-1];
	}
	for (int j = n-2; j >= 0; j--) {
		B[n-1][j] = A[n-1][j+1];
	}
	for (int i = n-2; i >= 0; i--) {
		B[i][0] = A[i+1][0];
	}
	B[0][0] = A[1][0];

	for (auto i : B) {
		cout << i << endl;
	}

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

