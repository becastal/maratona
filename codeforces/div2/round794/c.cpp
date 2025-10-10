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

void solve() {
	int n; cin >> n;
	vector<int> v(n), res;
	for (int& i : v) cin >> i;

	if (n&1) {
		cout << "NO" << endl;	
		return;
	}

	sort(v.begin(), v.end());
	for (int l = 0, r = n/2; l < n/2; l++, r++) {
		res.push_back(v[l]);
		res.push_back(v[r]);
	}

	int ok = 1;
	for (int i = 0; i < n and ok; i++) {
		ok &= (res[(i-1+n)%n] > res[i] and res[(i+1)%n] > res[i]) or
			  (res[(i-1+n)%n] < res[i] and res[(i+1)%n] < res[i]);
	}

	if (!ok) {
		cout << "NO" << endl;	
		return;
	}

	cout << "YES" << endl;
	for (int i : res) cout << i << ' '; cout << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

