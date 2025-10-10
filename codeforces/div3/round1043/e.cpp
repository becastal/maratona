#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	sort(rall(A));
	sort(rall(B));

	vector<ll> PA(n+1), PB(m+1);
	for (int i = 1; i <= n; i++) PA[i] = PA[i-1] + A[i-1];
	for (int i = 1; i <= m; i++) PB[i] = PB[i-1] + B[i-1];

	vector<array<int, 2>> C(n + m + 1);
	for (int i = 1, l = 0, r = 0; i < n + m + 1; i++) {
		if (l < n and r < m) {
			if (A[l] > B[r]) {
				l++;
			} else {
				r++;
			}
		} else if (l == n) {
			r++;
		} else if (r == m) {
			l++;
		}
		C[i] = {l, r};
	}

	for (int i = 0, x, y, z; i < q; i++) {
		cin >> x >> y >> z;
		auto [l, r] = C[z];
		
		if (l > x) {
			cout << PA[x] + PB[z - x] << endl;
		} else if (r > y) {
			cout << PB[y] + PA[z - y] << endl;
		} else {
			cout << PA[l] + PB[r] << endl;
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

