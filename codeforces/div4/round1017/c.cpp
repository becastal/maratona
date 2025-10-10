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

int solve() {
	int n; cin >> n;
	vector<int> res(2 * n);
	set<int> foi;
	for (int i = 1; i <= 2 * n; i++) {
		foi.insert(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0, x; j < n; j++) {
			cin >> x;
			foi.erase(x);
			res[i+j+1] = x;
		}
	}
	res[0] = *foi.begin();
	
	for (int i : res) cout << i << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
