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
	vector<int> res;

	if (n == 3) {
		cout << "2 1 3" << endl;
		return;
	}

	int ruim = 0;
	if (n&1) {
		n--, ruim = 1;
	}
	if ((n/2)&1) { 
		for (int i = 1; i <= n-4; i++) {
			res.push_back(i & 1 ^ 1 ? (i+5) | (1 << 25) : (i+5));		
		}
		res.push_back(2);
		res.push_back(1);
		res.push_back(3);
		res.push_back(1 | (1 << 25));
	} else {
		for (int i = 1; i <= n/2; i++) {
			res.push_back(i);
			res.push_back(i | (1 << 25));
		}
	}

	if (ruim) res.push_back(0);
	vector<int> x(2, 0);
	for (int i = 0; i < n; i++) {
		x[i&1] ^= res[i];
	}
	//cout << x[0] << ' ' << x[1] << endl;
	assert(x[0] == x[1]);
	
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
