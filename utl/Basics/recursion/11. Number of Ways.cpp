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
 
 	int s, e; cin >> s >> e;

	function<int(int)> f = [&] (int a) {
		if (a == e) return 1;
		if (a > e) return 0;

		return f(a + 1) + f(a + 2) + f (a + 3);
	};
 
 	cout << f(s) << endl;
    
    return(0);
}
