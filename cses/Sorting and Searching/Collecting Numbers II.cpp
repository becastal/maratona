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
	int n, q; cin >> n >> q;

	vector<int> A(n), pos(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i]; A[i]--;
		pos[A[i]] = i;
	}

	auto f = [&](int i) -> int {
		if (!i or i >= n) return 0;
		return pos[i] < pos[i-1];
	};

	int res = 1;
	for (int i = 0; i < n; i++) {
		res += f(i);
	}

	while (q--) {
		int l, r; cin >> l >> r; l--, r--;

		set<int> s;
		for (int i : {A[l], A[r]}) {
			if (i) s.insert(i);
			if (i+1 < n) s.insert(i+1);
		}

		for (int i : s) res -= f(i);

		pos[A[l]] = r, pos[A[r]] = l;
		swap(A[l], A[r]);

		for (int i : s) res += f(i);
		cout << res << endl;
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
