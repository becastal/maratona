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
		int n; cin >> n;
		string a, b; cin >> a >> b;
		
		int ok = 1;
		for (int i = 0; i < n and ok; i++) {
			if (b[i] == 'G') b[i] = 'B';
			if (a[i] == 'G') a[i] = 'B';
			ok &= a[i] == b[i];
		}

		cout << (ok ? "YES" : "NO") << endl;
	}
    
    return(0);
}
