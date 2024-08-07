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
		int n; cin >> n;
		vector<ll> v(n);
		for (ll& i : v) cin >> i;
		
		if (n == 1) {
			cout << "Second" << endl;
			continue;
		}

		ll res = 0;
		// so as pilhas com tamanho impar influenciam em como o jogo funciona, ja que se fosse par, eles podiam 
		// so alternar as jogadas e acabar exatamente como comecou.
		// uma pilha a[i] influncia no resultado como uma pilha de tamanho i em um jogo de nim normal.
		for (int i = 1; i < n; i++) {
			if (v[i] & 1) {
				res ^= i;
			}
		}
		cout << (res ? "First" : "Second") << endl;
	}
    
    return(0);
}
