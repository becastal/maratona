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
	for (int i = 1; i <= 26; i++) {
		for (int j = 1; j <= 26; j++) {
			for (int k = 1; k <= 26; k++) {
				if (i + j + k == n) {
					cout << char('a'-1+i) << char('a'-1+j) << char('a'-1+k) << endl;
					return;
				}
			}
		}
	}
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
