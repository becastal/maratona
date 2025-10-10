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
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<int> pre = v, suf = v;
	for (int i = 1; i < n; i++) {
		pre[i] = gcd(pre[i], pre[i-1]);
	}
	for (int j = n-2; j >= 0; j--) {
		suf[j] = gcd(suf[j], suf[j+1]);
	}

	for (int i = 1; i < n-1; i++) {
		if (gcd(pre[i-1], suf[i+1]) != v[i]) {
			cout << "YES" << endl;
			for (int j = 0; j < n; j++) {
				cout << (j == i ? 1 : 2) << ' ';
			}
			cout << endl;
			return 0;
		}
	}
	if (suf[1] != v[0]) {
		cout << "YES" << endl;
		for (int j = 0; j < n; j++) {
			cout << (j == 0 ? 1 : 2) << ' ';
		}
		cout << endl;
		return 0;
	}

	if (pre[n-2] != v[n-1]) {
		cout << "YES" << endl;
		for (int j = 0; j < n; j++) {
			cout << (j == n-1 ? 1 : 2) << ' ';
		}
		cout << endl;
		return 0;
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
