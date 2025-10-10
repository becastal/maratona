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

const int MAX = 2e5+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

int solve() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int ii = i ^ j;
			if (ii != 1 and divi[ii] == ii) {
				cout << i << ' ' << j << endl;
			}
		}
	}

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
