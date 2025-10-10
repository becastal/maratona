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

vector<int> V;
int solve() {
	int n; cin >> n;
	cout << upper_bound(V.begin(), V.end(), n) - V.begin() << endl;

	return(0);
}

int main()
{
    _;

	for (int i = 1; i * i <= (int)1e9; i++) {
		V.push_back(i * i);
	}

	for (int i = 1; i * i * i <= (int)1e9; i++) {
		V.push_back(i * i * i);
	}
	
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
