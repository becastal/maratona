#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int ok(int ult, const vector<int>& C, int rem) {
	if (rem == 0) return true;

	int mx = 0;
	for (int i = 0; i < 26; i++) if (i != ult) {
		mx = max(mx, C[i]);
	}

	if (ult == -1) {
		return 2 * mx <= rem + 1;
	}

	if (2 * C[ult] > rem) return false;
	if (2 * mx > rem + 1) return false;
	return true;
}

int solve() {
	string S, R = ""; cin >> S;
	int n = (int)S.size();

	vector<int> C(26, 0);
	for (char c : S) {
		C[c - 'A']++;
	}

	if (!ok(-1, C, n)) return cout << -1 << endl, 0;

	for (int i = 0, ult = -1; i < n; i++) {
		int c = -1;
		for (int j = 0; j < 26; j++) if (C[j] and j != ult) {
			C[j]--;
			if (ok(j, C, n - i - 1)) {
				c = j;
				break;
			}
			C[j]++;
		}
		assert(c != -1);
		R.push_back(char('A' + c));
		ult = c;
	}

	cout << R << endl;
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

