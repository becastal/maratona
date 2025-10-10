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
	int n, x, y; cin >> n >> x >> y; y--, x--;
	vector<int> res(n, 0);

	for (int i = y; i <= x; i++) {
		res[i] = 1;
	}

	for (int i = x+1, agr = 0; i < n; i++, agr ^= 1) {
		res[i] = (agr ? 1 : -1);	
	}
	for (int i = y-1, agr = 0; i >= 0; i--, agr ^= 1) {
		res[i] = (agr ? 1 : -1);	
	}

//	int xx = -1, yy = -1;
//	for (int i = 0, agr = 0, mx = agr; i < n; i++) {
//		agr += res[i];
//		if (agr > mx) {
//			mx = agr;
//			xx = i+1;
//		}
//	}
//	for (int i = n-1, agr = 0, mx = agr; i >= 0; i--) {
//		agr += res[i];
//		if (agr > mx) {
//			mx = agr;
//			yy = i+1;
//		}
//	}
//	assert(xx == x and yy == y);

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
