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
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<pair<int, int>> res;
	while (1) {
		if (A.size() == 1 or count(all(A), 0) == 0) {
			if (A.size() == 1) assert(A[0] == 0);
			res.emplace_back(1, A.size());
			break;
		}

		int pos = 0;
		for (; pos < A.size(); pos++) {
			if (A[pos] == 0) break;
		}

		int pos_;
		if (pos == A.size()-1) pos_ = pos-1;
		else pos_ = pos+1;

		int mex = (A[pos_] == 1 ? 2 : 1);
		A[pos_] = mex;
		A.erase(A.begin() + pos);

		res.emplace_back(min(pos, pos_) + 1, max(pos, pos_) + 1);
	}

	cout << res.size() << endl;
	for (auto [l, r] : res) cout << l << ' ' << r << endl;

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
