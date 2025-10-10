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
	string s; cin >> s;

	// bob ganha se ganhar todas na primeira rodad
	// (n, qualquer outra), (1, n-1)
	
	set<int> b;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') b.insert(i+1);	
	}

	if (b.size() > 1 and b.count(n)) return cout << "Bob" << endl, 0;
	if (b.count(1) and b.count(n-1)) return cout << "Bob" << endl, 0;
	cout << "Alice" << endl;

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
