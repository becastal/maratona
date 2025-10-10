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
	if (n == 1) return cout << 1 << endl, 0;
	if (n <= 3) return cout << "NO SOLUTION" << endl, 0;

	for (int i = 2; i <= n; i += 2) {
		cout << i << ' ';
	}
	for (int i = 1; i <= n; i += 2) {
		cout << i << ' ';
	}
	cout << endl;
    
    return(0);
}
