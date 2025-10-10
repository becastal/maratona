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

	int n, a, b; 
	cin >> n >> a >> b; 
	
	auto f = [&] (int x) {
		int res = 0;
		while (x) {
			res += x % 10;
			x /= 10;
		}
		return (res >= a and res <= b);
	};

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (f(i)) res += i;
	}

	cout << res << endl;
    
    return(0);
}
