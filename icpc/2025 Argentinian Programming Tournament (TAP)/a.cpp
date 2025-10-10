#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	string S, A = "TAP"; cin >> S;
	for (int i = 0, j = 0; i < (int)S.size(); i++) {
		if (S[i] == A[j]) j++;
		if (j > 2) return cout << "S" << endl, 0;
	}
	cout << "N" << endl;

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

