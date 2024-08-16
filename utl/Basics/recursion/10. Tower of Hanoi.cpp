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

	function<void(int, int, int, int)> hanoi = [&] (int a, int b, int c, int d) {
		if (d == 0) return;
		
		hanoi(a, c, b, d - 1);
		cout << a << ' ' << c << endl;
		hanoi(b, a, c, d - 1);
	};

	cout << (1 << n) - 1 << endl;
	hanoi(1, 2, 3, n);
    
    return(0);
}
