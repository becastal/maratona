#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> D;
	for (int i = 1; i <= 9; i++) {
		if (n % i == 0) {
			D.push_back(i);
		}
	}

	string S = "";
	for (int i = 0; i <= n; i++) {
		int ok = 0;
		for (int j : D) {
			if (!i or i % (n / j) == 0) {
				S.push_back(char('0' + j));
				ok = 1;
				break;
			}
		}
		if (!ok) S.push_back('-');
	}
	cout << S << endl;

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

