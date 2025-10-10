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

void solve() {
	ll n, k, x; cin >> n >> k >> x;

	// formar x com k valores de 1...n;
	// menor que posso formar eh sempre pa de 1, 2, ... k
	// maior que posso formar eh sempre pa de n, n-1, n-2, n-(k-1);
	// consigo formar todos entre menor e maior.
	
	ll menor = ((1 + k) * k) / 2;
	ll maior = ((n-k+1 + n) * k) / 2;

	cout << (x >= menor and x <= maior ? "yes" : "no") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
