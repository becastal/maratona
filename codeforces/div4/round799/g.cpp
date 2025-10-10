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
	vector<int> v(n), b(n-1, 0);
	for (int& i : v) cin >> i;

	for (int i = 0; i < n-1; i++) {
		b[i] = v[i] < (v[i+1] << 1);
	}

	vector<int> pre = {0};
	for (int i : b) pre.push_back(pre.back() + i);

	int res = 0;
	for (int i = k; i < n; i++) {
		res += pre[i] - pre[i-k] == k;
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
