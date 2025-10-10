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
	vector<int> v(n), f(n+1, 0);

	for (int& i : v) cin >> i, f[i]++;
	priority_queue<int> pq;
	for (int i : f) if (i) pq.push(-i);
	
	int ali = 0, res = 0;
	while (pq.size()) {
		int fi = -pq.top(); pq.pop();
		ali ^= 1;

		if (fi == 1) {
			res += ali * 2;
			continue;
		}

		res++;
	}

	cout << res << endl;
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
