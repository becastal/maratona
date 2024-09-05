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
	vector<int> a(n), b(n);
	ll sa = 0, sb = 0;
	for (int& i : a) cin >> i, sa += i;
	for (int& i : b) cin >> i, sb += i;

	int mina = *min_element(a.begin(), a.end());
	int minb = *min_element(b.begin(), b.end());

	cout << min((ll)n*mina + sb, (ll)n*minb + sa) << endl;
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
