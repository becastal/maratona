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
	int n, c; cin >> n >> c;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] += i+1;
	}

	sort(v.begin(), v.end());
	int res = 0;	
	for (int i = 0; i < n; i++) {
		if (c >= v[i]) {
			c -= v[i];		
			res++;
		} else break;
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
