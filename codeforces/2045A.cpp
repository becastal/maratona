#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S; cin >> S;

	map<char, int> C;
	for (char c : S) {
		C[c]++;
	}
	
	int res = 0;
	for (int i = 0; i <= min(C['N'], C['G']); i++) {
		for (int y = 0; y <= C['Y']; y++) {

			int vog = y;
			for (char c : {'A', 'E', 'I', 'O', 'U'}) {
				vog += C[c];	
			}

			int cons = C['Y'] - y + i;
			auto C_ = C;
			C_['N'] -= i, C_['G'] -= i;
			for (char c = 'B'; c <= 'Z'; c++) if (c != 'E' and c != 'I' and c != 'O' and c != 'U' and c != 'Y') {
				cons += C_[c];
			}

			int s = min(vog, cons / 2);
			res = max(res, 3 * s + min(2 * s, i));
		}
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

