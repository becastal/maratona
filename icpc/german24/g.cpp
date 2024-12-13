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

	ll n; cin >> n;

	auto f = [&] (ll i) {
		int cont = 0;
		int ii = i;
		while (i <= n) {
			cont++;
			i = 10 * i + ii;
			//dbg(i);
		}
		return cont;
	};

	int res = 0;
	for (int i = 1; i <= 9; i++) {
		res += f(i);	
	}

	int zeros = 0;
	ll i = 10;
	while (i <= n) {
		zeros++;
		i *= 10;
	}

	cout << res + max(zeros, 1) << endl;
    
    return(0);
}
