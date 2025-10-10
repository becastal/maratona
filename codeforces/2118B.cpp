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
	//vector<vector<int>> A(n, vector<int>(n));
	//for (auto& v : A) {
	//	iota(v.begin(), v.end(), 1);
	//}

	vector<tuple<int, int, int>> res;
	for (int i = 2; i < n; i++) {
		int k = n - i + 1;
		res.emplace_back(i, 1, k);
		res.emplace_back(i, k+1, n);
	}
	res.emplace_back(1, 1, n);
	res.emplace_back(n, 2, n);

	cout << res.size() << endl;
	for (auto [a, b, c] : res) {
		cout << a << ' ' << b << ' ' << c << endl;
		//reverse(A[a-1].begin() + b - 1, A[a-1].begin() + c);
	}

	//cout << "-" << endl;
	//for (auto v : A) {
	//	for (int i : v) {
	//		cout << i << ' ';
	//	}
	//	cout << endl;
	//}

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
