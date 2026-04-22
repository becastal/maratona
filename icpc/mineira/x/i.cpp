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
// encaramos como um problema de dp, mas era mais facil encarar como um problema de combinatoria.
// se o problema fosse limitado a apenas N e S, por exemplo, eh evidente que so seria possivel que ele voltasse para o inicio do plano se ele completasse exatamente o mesmo numero de movimentos para N e para S, entao fica facil de contar.
// essa mesma ideia, mas transposta pra um cenario em que existem diversas direcoes, funciona no mesmo sentido, mas eh importante notar que somente para sentidos opostos.
const int MAX = 2*5e3 + 10;

int MOD;

ll fat[MAX], ifat[MAX];

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

void build() {
	fat[0] = ifat[0] = 1;
	for (ll i = 1; i < MAX; i++) fat[i] = i*fat[i - 1]%MOD;
	for (ll i = 1; i < MAX; i++) ifat[i] = inv(fat[i], MOD);
}

ll choose(int n, int m) {
	if (n < m or m < 0) return 0;
	return fat[n]*ifat[m]%MOD*ifat[n - m]%MOD;
}

int main() { _

	int k; cin >> k >> MOD;
	build();

	ll ans = 0;
	for (int n = 0; n <= k; n++) {
		for (int l = 0; l <= k; l++) {
			ll cur = choose(k, 2*n)*choose(2*n, n)%MOD;
			int over = 2*l - (k - 2*n);
			cur = cur*choose(2*n, over)%MOD*choose(2*l, l)%MOD;
			ans = (ans + cur)%MOD;
		}
	}

	cout << ans << endl;

	exit(0);
}
