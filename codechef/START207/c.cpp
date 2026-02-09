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

	if (count(all(S), '1') == 0) return cout << 0 << endl, 0;

	int l, r, res = 0;
	for (l = 0; l < n and S[l] == '0'; l++);
	for (r = n-1; r >= 0 and S[r] == '0'; r--);
	for (int i = l + 1; i < r; i++) res += S[i] == '0';

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

