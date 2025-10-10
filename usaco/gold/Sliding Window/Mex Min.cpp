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
	int n, m; cin >> n >> m;
	vector<int> A(n), F(n);
	set<int> S = {n};
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		S.insert(i);
	}

	auto add = [&](int x) {
		if (++F[x] == 1) S.erase(x);
	};
	auto rem = [&](int x) {
		if (--F[x] == 0) S.insert(x);
	};
	auto query = [&]() { return *S.begin(); };

	for (int i = 0; i < m; i++) {
		add(A[i]);	
	}
	int res = query();

	for (int i = m; i < n; i++) {
		add(A[i]);
		rem(A[i-m]);
		res = min(res, query());
	}
	cout << res << endl;

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
