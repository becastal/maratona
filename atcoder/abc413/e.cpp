#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> A(1 << n);
	for (int& i : A) cin >> i;

	function<vector<int>(int, int)> f = [&](int l, int r) -> vector<int> {
		if (r - l == 1) return { A[l] };

		int m = l + r >> 1;
		vector<int> L = f(l, m), R = f(m, r);
		if (L.front() > R.front()) swap(L, R);
		for (int i : R) L.push_back(i);
		return L;
	};
	vector<int> res = f(0, 1 << n);
	for (int i : res) cout << i << ' '; cout << endl;

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
