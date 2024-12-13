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
		// pra n ser fibo ou 5 * n * n + 4 eh quadrado perfeito ou 5 * n * n - 4 eh
		ll n; cin >> n;
		ll mais = 5 * n * n + 4, menos = 5 * n * n - 4;
		cout << ((ll)sqrt(mais) * (ll)sqrt(mais) == mais or (ll)sqrt(menos) * (ll)sqrt(menos) == menos ? "IsFibo" : "IsNotFibo") << endl;
	}
    
    return(0);
}
