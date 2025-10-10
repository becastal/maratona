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
	
	int n; cin >> n;
	for (int i = 0, x, y; i < n; i++) {
		// ele alcanca (x, y) em max(abs(x), abs(y)) segs.
		cin >> x >> y;
		bool res = false;
		for (int j = 0; j < 100; j++) {
			if (max(abs(x), abs(y - j)) - 1 <= j) {
				res = true;
				break;
			}
		}
		cout << (res ? "YES" : "NO") << endl;
	}
    
    return(0);
}
