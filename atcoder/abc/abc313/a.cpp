#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, mx = 0, mxc = 0; cin >> n;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		if (i > mx) {
			mxc = 1;
			mx = i;
		} else if (i == mx) {
			mxc++;
		}
	}

	if (A[0] == mx and mxc == 1) return cout << 0 << endl, 0;
	cout << mx - A[0] + 1 << endl;


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

