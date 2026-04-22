#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int q; cin >> q;

	multiset<int> M;
	while (q--) {
		int tp, h; cin >> tp >> h;

		if (tp == 1) {
			M.insert(h);
		} else if (tp == 2) {
			vector<int> Rem;
			for (auto it = M.begin(); it != M.end() and *it <= h; it++) {
				Rem.push_back(*it);
			}
			for (int i : Rem) {
				M.erase(M.find(i));
			}

		} else assert(0);

		cout << (int)M.size() << endl;
	}

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

