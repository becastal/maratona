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
	string a, b; cin >> a >> b;
	int n = (int)a.size(), m = (int)b.size();
	// tem que ter a como substring e b como subsequence;
	// tentar colocar a em b;

	if (a == b) return cout << n << endl, 0;
	


	return cout << INF << endl, 0;
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
