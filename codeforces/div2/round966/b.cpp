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
	vector<int> a(n), b(n), d(n);

	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	
	int cont = 0, m = 0, mi = INF;
	for (int i = 0; i < n; i++) {
		if (b[i] > a[i]) {
			cont++;
			m = max(m, b[i]-a[i]); 
		} else {
			mi = min(mi, a[i]-b[i]);
		}
	}

	cout << (!cont or (cont == 1 and m <= mi) ? "YES" : "NO") << endl;
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
