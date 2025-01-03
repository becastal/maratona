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
	map<int, int> freq, freqi;
	vector<int> v(n);
	for (int& i : v) cin >> i, freq[i]++;
	
	if (freq.size() == 1) return cout << "NO" << endl, 0;
	
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << (i == 1 ? 'B' : 'R');
	}

	cout << endl;

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
