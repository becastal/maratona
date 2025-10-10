#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	int mn = 0, pos = -1;
	for (int i = 0, c = 0; i < n; i++) {
		c += (S[i] == '(' ? +1 : -1);
		if (mn > c) {
			mn = c;
			pos = i;
		}
	}
	cout << (pos + 1) % n << endl;

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

