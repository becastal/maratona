#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	
	vector<int> A(n), P(n+1);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		P[A[i]] = i;
	}

	vector<int> da(n, 0);
	da[P[n]] = 1;
	for (int i = n; i >= 1; i--) {
		if (!da[P[i]]) return cout << "NO" << endl, 0;
		for (int j : {-1, +1}) {
			if (P[i] + j >= 0 and P[i] + j < n) {
				da[P[i] + j] = 1;
			}
		}
	}
	cout << "YES" << endl;

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

