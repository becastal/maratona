#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, d; cin >> n >> d;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	multiset<int> M;
	map<int, int> F;

	auto add = [&](int a) {
		M.insert(A[a]);
		auto it = M.find(A[a]);

		if (it != M.begin()) {
			int dif = A[a] - *prev(it);
			F[dif]++;
		}
		if (next(it) != M.end()) {
			int dif = *next(it) - A[a];
			F[dif]++;
		}

		if (it != M.begin() and next(it) != M.end()) {
			int dif = *next(it) - *prev(it);
			if (--F[dif] == 0) F.erase(dif);
		}
	};
	auto rem = [&](int a) {
		auto it = M.find(A[a]);

		if (it != M.begin()) {
			int dif = A[a] - *prev(it);
			if (--F[dif] == 0) F.erase(dif);
		}
		if (next(it) != M.end()) {
			int dif = *next(it) - A[a];
			if (--F[dif] == 0) F.erase(dif);
		}

		if (it != M.begin() and next(it) != M.end()) {
			int dif = *next(it) - *prev(it);
			F[dif]++;
		}
		M.erase(it);
	};
	auto mind = [&]() {
		return F.begin()->first;
	};

	int res = 0;
	for (int r = 0, l = 0; r < n; r++) {
		add(r);
		while (r - l + 1 >= 2 and mind() < d) {
			rem(l++);	
		}

		res += r - l + 1;
	}
	cout << res << endl;

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


