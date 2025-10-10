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
	int n; cin >> n;
	int m = 2*n;

	map<int, int> Fi;
	vector<int> A(m);
	for (int& i : A) cin >> i, Fi[i]++;
	sort(all(A));

	// x = A[n-1] + A[j], j < n-1
	// ja que tenho que resolver sempre o maior primeiro
	// da pra testar cada x em mlogm

	for (int i = 0; i < m-1; i++) {
		auto F = Fi;
		int x = A.back() + A[i];

		vector<pair<int, int>> res;
		for (int j = 0; j < n; j++) {
			int a = F.rbegin()->f, b = x - a;
			if (!--F[a]) F.erase(a);
			if (!F.count(b)) break;	
			if (!--F[b]) F.erase(b);

			res.emplace_back(a, b);
			x = max(a, b);
		}

		if (res.size() == n) {
			cout << "YES" << endl << A.back() + A[i] << endl;
			for (auto [a, b] : res) {
				cout << a << ' ' << b << endl;
			}
			return 0;
		}
	}
	cout << "NO" << endl;
	
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
