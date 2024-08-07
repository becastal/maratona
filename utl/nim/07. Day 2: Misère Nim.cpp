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

int main()
{
    _;
	
	int t; cin >> t;
	while (t--) {
		int n, res = 0, uns = 0; cin >> n;
		for (int i = 0, si; i < n; i++) {
			cin >> si; res ^= si;
			if (si == 1) uns++;
		}
		cout << (res or uns == n ? "First" : "Second") << endl;
	}
    
    return(0);
}
