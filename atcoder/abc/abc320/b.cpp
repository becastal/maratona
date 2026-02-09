#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	auto pal = [&](int a, int b) {
		for (int i = a, j = b; i < j; i++, j--) {
			if (S[i] != S[j]) return 0;
		}
		return 1;
	};

	int res = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (pal(i, j)) {
				res = max(res, j - i + 1);
			}
		}
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

