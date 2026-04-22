#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, x, k; cin >> n >> x >> k;
	string S; cin >> S;

	int bom = 0;
	for (int i = 0, p = x; i < n; i++) {
		char c = S[i];
		if (c == 'L') {
			p--;
		} else {
			p++;
		}
		k--;
		if (!p) {
			bom = 1;
			break;
		}
		if (!k) break;
	}
	if (!k) return cout << bom << endl, 0;
	if (!bom) return cout << 0 << endl, 0;

	int cont = -1;
	for (int i = 0, p = 0; i < n; i++) {
		char c = S[i];
		if (c == 'L') {
			p--;
		} else {
			p++;
		}

		if (i and !p) {
			cont = i + 1;
			break;
		}
	}
	int add = (cont == -1 ? 0 : k / cont);
	cout << add + 1 << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

