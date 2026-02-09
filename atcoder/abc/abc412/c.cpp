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

	vector<int> B(A);
	sort(all(B));
	B.erase(unique(all(B)), B.end());

	int a = A[0], b = A[n-1], res = 2;
	while (2 * a < b) {
		auto it = upper_bound(all(B), 2 * a);
		if (it == B.end()) return cout << -1 << endl, 0;
		it--;
		if (*it == a) return cout << -1 << endl, 0;
		a = *it;
		res++;
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
