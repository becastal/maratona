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
	int n, k; cin >> n >> k;
	vector<int> v(n);
	map<int, int> f;
	ll s = 0;
	for (int& i : v) cin >> i, f[i]++, s += i;

	if (f.rbegin()->f - f.begin()->f > k + 1 or
	   (f.rbegin()->f - f.begin()->f == k + 1 and f.rbegin()->s > 1)) return cout << "Jerry" << endl, 0;

	cout << (s & 1 ? "Tom" : "Jerry") << endl;

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
