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
	int n; cin >> n;
	vector<int> A(n), res(n+1, 1);

	for (int& i : A) cin >> i;

	map<int, int> M;
	for (int i = 0; i < n; i++) {
		map<int, int> M_;

		for (auto [g, t] : M) {
			int ng = gcd(g, A[i]);

			if (!M_.count(ng)) M_[ng] = t;
			else M_[ng] = min(M_[ng], t);
		}

		if (!M_.count(A[i])) M_[A[i]] = i;
		else M_[A[i]] = min(M_[A[i]], i);

		for (auto [g_, t_] : M_) {
			res[i - t_ + 1] = max(res[i - t_ + 1], g_);
		}

		M = move(M_);
	}

	for (int i = n-1; i >= 1; i--) {
		res[i] = max(res[i], res[i+1]);
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << " \n"[i==n];
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
