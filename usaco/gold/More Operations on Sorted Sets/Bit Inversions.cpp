#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	string A; cin >> A;
	int n = (int)A.size();

	set<pair<int, int>> S;
	map<int, int> F; 

	auto add = [&](int l, int r) {
		S.emplace(l, r);
		F[r - l + 1]++;
	};
	auto rem = [&](int l, int r) {
		assert(S.count({l, r}));	
		S.erase({l, r});
		if (!--F[r - l + 1]) F.erase(r - l + 1);
	};

	for (int l = 0, r; l < n; l = r) {
		r = l + 1;

		while (r < n and A[l] == A[r]) r++;
		add(l, r-1);
	}

	int q; cin >> q;
	while (q--) {
		int p; cin >> p; p--;

		auto it = S.upper_bound({p, INF}); --it;
		auto [l, r] = *it;
		assert(l <= p and p <= r);

		if (p > l and p < r) {
			rem(l, r);
			add(l, p-1);			
			add(p, p);
			add(p+1, r);
		} else if (l == r) {
			int L = -1, R = -1;
			if (it != S.begin()) {
				auto [li, ri] = *prev(it);	
				rem(li, ri);
				L = li;
			} else L = l;

			if (next(it) != S.end()) {
				auto [li, ri] = *next(it);
				rem(li, ri);
				R = ri;
			} else R = r;

			rem(l, r);
			add(L, R);
		} else if (p == l) {
			if (it != S.begin()) {
				auto [li, ri] = *prev(it);
				rem(li, ri);
				add(li, ri+1);
			} else {
				add(l, l);	
			}
			rem(l, r);
			add(l+1, r);
		} else if (p == r) {
			if (next(it) != S.end()) {
				auto [li, ri] = *next(it);
				rem(li, ri);
				add(li-1, ri);
			} else {
				add(r, r);
			}
			rem(l, r);
			add(l, r-1);
		}

		cout << F.rbegin()->f << "\n "[!!q];
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
