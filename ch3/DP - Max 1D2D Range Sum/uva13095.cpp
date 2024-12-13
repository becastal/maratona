#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;

int n; 
void solve() {
    vector<vector<int>> v(10);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x].push_back(i + 1);
    }

    int q; cin >> q;
    while (q--) {
        int l, r, res = 0; cin >> l >> r;

        for (int i = 0; i < 10; i++) {
			res += lower_bound(v[i].begin(), v[i].end(), l) < upper_bound(v[i].begin(), v[i].end(), r);
        }

        cout << res << endl;
    }
}

int main() {
    _;

	while (cin >> n) {
		solve();
	}

    return 0;
}

