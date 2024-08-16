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
	function<void(ll)> f = [&] (ll a) {
		cout << a << ' ';
		if (a == 1) return;
		ll prox = (a % 2 ? 3 * a + 1 : a / 2);
		f(prox);
	};
 
	f(n);
	cout << endl;
    
    return(0);
}
