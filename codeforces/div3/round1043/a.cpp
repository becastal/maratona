#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	string A; cin >> A;

	int m; cin >> m;
	string B, S; cin >> B >> S;
	for (int i = 0; i < m; i++) {
		if (S[i] == 'D') {
			A = A + B[i];
		} else {
			A = B[i] + A;
		}
	}
	cout << A << endl;

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

