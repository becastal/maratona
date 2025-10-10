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
		int n, k; cin >> n >> k;

		if (n & 1) {
			cout << 1 + (n - k + (k - 1 - 1)) / (k - 1) << endl;	
		} else {
			cout << (n + (k - 1 - 1)) / (k - 1) << endl;
		}
	}
    
    return(0);
}
