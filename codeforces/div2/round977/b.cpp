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
	int n, x; cin >> n >> x;
	map<int, int> freq;
	vector<int> v(n);
	for (int& i : v) cin >> i, freq[i]++;

	for (int i = 0; i < n; i++) {
		if (!freq[i]) {
			return cout << i << endl, 0;
		}
		freq[i+x] += freq[i]-1;
	}
	cout << n << endl;
	return 0;
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
