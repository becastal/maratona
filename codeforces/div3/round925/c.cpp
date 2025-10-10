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
    int n; 
    cin >> n;

    vector<int> v(n), igual(n, 0);
    for (int& i : v) cin >> i;

	int tudo_igual = 1;
	for (int i = 1; i < n and tudo_igual; i++) {
		tudo_igual &= v[i] == v[i-1];
	}
	if (n == 1 or tudo_igual) return cout << 0 << endl, 0;

	int l = 0, r = n-1;
	while (l < n and v[l] == v[0]) l++;
	while (r >= 0 and v[r] == v[n-1]) r--;

	if (v[0] == v[n-1]) {
		cout << r - l + 1 << endl;
	} else {
		cout << min(n - l, r+1) << endl;
	}

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
