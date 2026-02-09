#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;
	string S; cin >> S;

	int soa = count(all(S), 'A') == n;
	while (q--) {
		int a; cin >> a;
		if (soa) {
			cout << a << endl;
		} else {
			int res = 0;
			for (int i = 0; a; i = (i + 1) % n) {
				a = (S[i] == 'A' ? a - 1 : a / 2);
				res++;
			}
			cout << res << endl;
		}
	}

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

