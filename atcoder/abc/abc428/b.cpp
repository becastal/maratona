#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	string S; cin >> S;

	map<string, int> F;
	for (int i = 0; i + k <= n; i++) {
		F[S.substr(i, k)]++;
	}

	int mx = INT_MIN;
	for (auto [a, b] : F) {
		mx = max(mx, b);
	}
	
	vector<string> R;
	for (auto [a, b] : F) {
		if (b == mx) {
			R.push_back(a);
		}
	}

	cout << mx << endl;
	for (int i = 0; i < (int)R.size(); i++) {
		cout << R[i] << " \n"[i==(int)R.size()-1];
	}

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

