#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	vector<string> A = {
		"ab",
		"ac",
		"ad",
		"ae",
		"bc",
		"bd",
		"be",
		"cd",
		"ce",
		"de"
	};

	int res = 0;
	for (int i = 0; i < (1 << 10); i++) {
		map<char, int> M;
		for (int j = 0; j < 10; j++) {
			M[A[j][i >> j & 1]]++;
		}
		
		int ok = 1;
		for (auto [a, b] : M) {
			ok &= b == 2;
		}
		res += ok;
	}
	cout << res << endl;

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

