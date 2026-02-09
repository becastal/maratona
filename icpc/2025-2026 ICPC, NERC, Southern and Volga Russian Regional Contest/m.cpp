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

	int s = count(all(S), '1'), res = s;
	for (int i = 0; i < n; i++) if (S[i] == '1') {
		int agr = 0;
		for (int j : {i-1, i+1}) if (j >= 0 and j < n) {
			agr += (S[j] == '1');
		}
		res = min(res, s - agr);
	}
	cout << res << endl;

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

