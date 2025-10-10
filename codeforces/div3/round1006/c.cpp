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
	int n, x; cin >> n >> x;
	vector<int> res;

	int or_ = 0;
	for (int i = 0; i < n; i++) {
		int ok = 1;
		for (int j = 0; j < 31 and ok; j++) {
			if (i & (1 << j) and !(x & (1 << j))) ok = 0;
		}

		if (ok) {
			res.push_back(i);
			or_ |= i;
		}
		else break;
	}

	if (or_ != x) {
		if (res.size() == n) res.pop_back();
		res.push_back(x);
	}
	
	while (res.size() < n) res.push_back(0);

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
