#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {

//	int n = 5;
//	vector<int> A(n);
//	iota(A.begin(), A.end(), 1);
//	map<int, vector<int>> S;
//
//	do {
//		int s = 0;
//		for (int i = n-1, agr = A.back(); i >= 0; i--) {
//			s += (agr = min(agr, A[i]));
//		}
//		S[s] = A;
//
//		if (s == 10) {
//			for (auto i : A) cout << i << ' '; cout << endl;
//		}
//	} while (next_permutation(A.begin(), A.end()));

	ll n, m; cin >> n >> m;
	if (m < n or m > (1 + n) * n / 2) return cout << -1 << endl, 0;

	vector<ll> d(n);
	for (ll i = n-1, mx = n; i >= 0; i--) {
		d[i] = min(mx, m - i);
		m -= d[i];
		if (d[i] == mx) mx--;
	}

	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}

	vector<int> p(n);
	for (int i = n-1; i >= 0; i--) {
		if (s.count(d[i])) s.erase(p[i] = d[i]);
		else {
			p[i] = *s.rbegin();
			s.erase(*s.rbegin());
		}
	}
	//for (int i : d) cout << i << ' '; cout << endl;
	//for (int i : p) cout << i << ' '; cout << endl;

	vector<pair<int, int>> ed;
	for (int i = 0; i < n-1; i++) {
		ed.emplace_back(p[i], p[i+1]);
	}
	cout << p.back() << endl;
	for (auto [u, v] : ed) {
		cout << u << ' ' << v << endl;
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
