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
	string a, b; cin >> a >> b;

	int tot = 0, cont = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '*') {
			tot ++;
			cont += b[i] != '*';
		}
	}

	cout << fixed << setprecision(2) << double(cont) / tot << endl;

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
