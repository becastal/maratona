#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Bit {
	int n;
	vector<int> A;

	Bit(int n_) : n(n_), A(n+1) {}
	void update(int i, int x) {
		for (i++; i <= n; i +=i&-i) {
			A[i] = max(A[i], x);
		}
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) {
			res = max(res, A[i]);
		}
		return res;
	}
};

int solve() {
	int n; cin >> n;
	vector<int> B;
	vector<array<int, 3>> A(n);
	for (auto& [a, b, c] : A) {
		cin >> a >> b >> c;
		B.push_back(b);
	}
	sort(all(A));

	sort(all(B));
	B.erase(unique(all(B)), B.end());
	int m = (int)B.size();

	map<array<int, 2>, int> C;
	for (auto& [a, b, c] : A) {
		C[{a, b}] += c;
	}

	map<int, vector<array<int, 2>>> M;
	for (auto [par, c] : C) {
		auto [a, b] = par;
		b = lower_bound(all(B), b) - B.begin();

		M[a].push_back({b, c});
	}

	Bit bit(m);
	for (auto [a, V] : M) {
		vector<array<int, 2>> updates;
		for (auto [b, c] : V) {
			updates.push_back({b, bit.pref(b - 1) + c});
		}

		for (auto [b, x] : updates) {
			bit.update(b, x);
		}
	}
	cout << bit.pref(m-1) << endl;

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

