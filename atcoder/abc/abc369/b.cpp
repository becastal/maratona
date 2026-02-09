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
	int l, r;
	l = r = -1;

	int res = 0;
	for (int i = 0, x; i < n; i++) {
		cin >> x; 
		char c; cin >> c;

		if (c == 'R') {
			if (r != -1) res += abs(r - x);
			r = x;
		} else {
			if (l != -1) res += abs(l - x);
			l = x;
		}
	}
	cout << res << endl;
    
    return(0);
}
