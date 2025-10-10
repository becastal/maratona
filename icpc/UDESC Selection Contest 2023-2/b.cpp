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
	int n, k, ms = 0; cin >> n >> k;
	string s; cin >> s;
	
	for (int i = n-1; i >= 0; i--) {
		ms = (ms + (s[i] == '1' ? !(i & 1) + 1 : 0)) % 3;
	}
	cout << ms << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
