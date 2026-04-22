#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, q; cin >> n >> q;
	vector<array<int, 2>> P(n);
	map<array<int, 2>, int> M;

	auto comprime = [&](array<int, 2> a) {
		int g = gcd(abs(a[0]), abs(a[1]));
		return array<int, 2>{a[0] / g, a[1] / g};
	};

	for (auto& [x, y] : P) { 
		cin >> x >> y;
	}

	for (auto p : P) {
		M[comprime(p)]++;
	}
	
	vector<array<int, 2>> A;
	for (auto [a, b] : M) {
		A.push_back(a);
	}
	int m = (int)A.size();

	auto upper = [](array<int, 2> a) {
		return (a[1] > 0) or (a[1] == 0 and a[0] > 0);
	};
	sort(all(A), [&](array<int, 2> a, array<int, 2> b) {
		int ua = upper(a), ub = upper(b);	
		if (ua != ub) return ua > ub;
		return a[0] * b[1] - a[1] * b[0] > 0;
	});

	vector<int> Pref(m + 1);
	map<array<int, 2>, int> Pos;
	for (int i = 0; i < m; i++) {
		Pref[i+1] = Pref[i] + M[A[i]];
		Pos[A[i]] = i;
	}

	for (int i = 0, a, b; i < q; i++) {
		cin >> a >> b; a--, b--;
		int l = Pos[comprime(P[a])], r = Pos[comprime(P[b])];

		if (r <= l) {
			cout << Pref[l + 1] - Pref[r] << endl;
		} else {
			cout << (Pref[m] - Pref[r]) + Pref[l + 1] << endl;
		}
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

