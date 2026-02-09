#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S, T; cin >> S >> T;

	for (int i = 0; i < n; i++) {
		if (S[i] == '0') S[i] = 'o';
		if (S[i] == '1') S[i] = 'l';
		if (T[i] == '0') T[i] = 'o';
		if (T[i] == '1') T[i] = 'l';
		if (S[i] != T[i]) return cout << "No" << endl, 0;
	}
	cout << "Yes" << endl;

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

