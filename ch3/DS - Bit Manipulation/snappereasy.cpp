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

	int t, cas = 0; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		cout <<  "Case #" << ++cas << ": " << ((k+1) % (1 << n) == 0 ? "ON" : "OFF") << endl;
	}
    
    return(0);
}
