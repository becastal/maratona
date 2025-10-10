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

	int a,b,c,d; cin >> a >> b >> c >> d;

	if(a == c) return d - b;

	else{
		int r = n - b + 1;
		a++;
		r+= (c-a) *(n+1) + d;
		return r;
	}

	return(0);
}

int main()
{
    _;

	int t = 1;// cin >> t;
	while (t--) {
		int r = solve();
		cout << r << endl;
	}
    
    return(0);
}
