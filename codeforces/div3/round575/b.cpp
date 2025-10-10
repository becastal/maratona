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
	int n, k, nimp = 0; cin >> n >> k;
	vector<int> v(n), pos;

	int ii = 1;
	for (int& i : v) {
		cin >> i, i &= 1, nimp += i;
		if (i) pos.push_back(ii);
		ii++;
	}

	if (nimp < k or (k - nimp) & 1) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	vector<int> res;
	for (int i = 0, j = (int)pos.size() - 1; i < k; i++) {
		res.push_back(pos[j--]);
	}

	reverse(res.begin(), res.end());
	res[res.size()-1] = n;
	for (int i : res) cout << i << ' '; cout << endl;
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
