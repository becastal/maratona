#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
// #define int ll

void fact(map<int, int>& v, int n) {
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			v[i]++;
			n /= i;
		}
	}
	if (n != 1) {
		v[n]++;
	}
}

int solve() {
	int n, m; cin >> n >> m;

	vector<int> A(n), B(m);
	vector<map<int, int>> FA(n), FB(m);
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] != 1) {
			fact(FA[i], A[i]);
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> B[i];
		if (B[i] != 1) {
			fact(FB[i], B[i]);
		}
	}

	map<map<int, int>, int> M;
	for (int mask = 1; mask < (1 << n); mask++) {
		map<int, int> Agr;
		for (int i = 0; i < n; i++) if (mask >> i & 1) {
			for (auto [p, e] : FA[i]) {
				Agr[p] += e;
			}
		}
		M[Agr] = mask;
	}

	for (int mask = 1; mask < (1 << m); mask++) {
		map<int, int> Agr;
		for (int i = 0; i < m; i++) if (mask >> i & 1) {
			for (auto [p, e] : FB[i]) {
				Agr[p] += e;
			}
		}
		if (M.count(Agr)) {
			cout << "Y" << endl;

			int mask_ = M[Agr];
			cout << __builtin_popcount(mask_) << ' ' << __builtin_popcount(mask) << endl;
			for (int i = 0; i < n; i++) if (mask_ >> i & 1) {
				cout << A[i] << ' ';
			}
			cout << endl;
			for (int i = 0; i < m; i++) if (mask >> i & 1) {
				cout << B[i] << ' ';
			}
			cout << endl;


			return 0;
		}
	}
	cout << "N" << endl;

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

