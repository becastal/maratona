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
	vector<int> A(n);
	for (int& i : A) cin >> i;

	auto da = [&](int m) {
		int i = max_element(A.begin() + m, A.end()) - A.begin();
		return is_sorted(A.begin() + m, A.begin() + i + 1, [&](int a, int b) { return a < b; }) and 
			   is_sorted(A.begin() + i, A.end(), [&](int a, int b) { return a > b; });
	};

	int l = 0, r = n-1, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			r = m-1;
			res = m;
		} else {
			l = m+1;
		}
	}
	cout << res << endl;

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
