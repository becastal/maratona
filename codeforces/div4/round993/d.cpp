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
	vector<int> v(n), apareceu(n+1, 0);
	set<int> usei, ocorr;
	for (int i = 1; i <= n; i++) {
		usei.emplace(i);
	}

	for (int& i : v) {
		cin >> i;
		if (usei.count(i)) usei.erase(i);
	}

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		if (ocorr.count(v[i])) {
			b[i] = *usei.begin();
			usei.erase(*usei.begin());
		} else {
			b[i] = v[i];
		}

		ocorr.insert(v[i]);
	}

	for (int i : b) cout << i << ' '; cout << endl;
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
