#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<array<int, 2>> R;
	R.reserve(n * (n - 1) / 2);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			R.push_back({i, j});
		}
	}

	sort(all(R), [&](auto& a, auto& b) {
		auto [ai, aj] = a;
		auto [bi, bj] = b;
		return make_tuple(ai, A[aj], -aj) < make_tuple(bi, A[bj], -bj);
	});

	while (q--) {
		int x; cin >> x; x--;
		cout << R[x][0] + 1 << ' ' << R[x][1] + 1 << endl;
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

