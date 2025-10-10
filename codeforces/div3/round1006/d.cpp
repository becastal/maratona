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
	vector<int> v(n); 
	for (int& i : v) cin >> i;

	int res = 0, x = 1, y = 1;
	for (int i = 0; i < n; i++) {
		int agr = 0;
		for (int j = i+1; j < n; j++) {
			agr += (v[i] == v[j] ? 0 : (v[i] > v[j] ? 1 : -1));
			if (agr > res) {
				res = agr;
				x = i+1;
				y = j+1;
			}
		}
	}

	cout << x << ' ' << y << endl;
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
