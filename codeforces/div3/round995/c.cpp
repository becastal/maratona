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
	int n, m, k; cin >> n >> m >> k;

	int xs = 0;
	for (int i = 1; i <= n; i++) {
		xs ^= i;
	}

	vector<int> M(m);
	for (int& i : M) cin >> i;

	set<int> sei;
	int xs_eu = 0;
	for (int i = 0; i < k; i++) {
		int ki; cin >> ki;
		xs_eu ^= ki;
		sei.insert(ki);
	}

	for (int i : M) {
		cout << int(sei.size() == n-1 and !sei.count(i) or sei.size() == n);
	}

	cout << endl;
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
