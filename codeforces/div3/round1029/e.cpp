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

	vector<int> a(n), b(n), vi(n+1, 0);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	if (a[n-1] == b[n-1]) return cout << n << endl, 0;

	for (int i = n-2; i >= 0; i--) {
		if (a[i] == b[i] or a[i] == a[i+1] or b[i] == b[i+1] or vi[a[i]] or vi[b[i]]) {
			return cout << i + 1 << endl, 0;
		}
		if (i + 1 < n) vi[a[i+1]] = vi[b[i+1]] = 1;
	}
	cout << 0 << endl;

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
