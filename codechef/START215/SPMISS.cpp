#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, c; cin >> n >> c;

	vector<int> A(n), B(n);
	for (int& i : A) cin >> i;

	string S; cin >> S;	

	ll res = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (S[i] == '1') {
			b += A[i];
		} else {
			res += A[i];	
		}
	}

	if (res >= c and res - c + b >= res) {
		res += - c + b;
	}
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

