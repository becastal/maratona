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
	vector<int> cont(3, 0);
	for (int i = 0, x; i < n; i++) {
		cin >> x; cont[x]++;
	}

	if (cont[1] & 1 ^ 1 and cont[2] & 1 ^ 1) return cout << "yes" << endl, 0;
	if (cont[2] & 1 and cont[1] >= 2 and cont[1] & 1 ^ 1) return cout << "yes" << endl, 0;
	cout << "no" << endl;
	return 0;
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
