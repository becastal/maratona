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
	int n, k; cin >> n >> k;

	vector<int> cont(26, 0);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		cont[c-'a'] ^= 1;
	}
	
	int imp = count(cont.begin(), cont.end(), 1), par = n - imp;

	if (n - k & 1) {
		int falta = (imp ? imp-1 : 1);
		cout << (k >= falta and k - falta & 1 ^ 1 ? "YES" : "NO") << endl;
	} else {
		cout << (k >= imp and k - imp & 1 ^ 1 ? "YES" : "NO") << endl;
	}
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
