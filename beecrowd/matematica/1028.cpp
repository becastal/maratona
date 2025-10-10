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

int gcd(int a, int b) {
	return !a ? b : gcd(b % a, a);
}

int main()
{
    _;

	int n; cin >> n;
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		cout << gcd(max(a, b), min(a, b)) << endl;
	}
    
    return(0);
}
