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

	vector<int> fib(42, 0);
	fib[1] = fib[2] = 1;
	for (int i = 3; i <= 41; i++) {
		fib[i] = fib[i-1]+fib[i-2];
	}

	int n; cin >> n;
	cout << fib[n + 1] << endl;
    
    return(0);
}
