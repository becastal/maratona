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
const int mod = 998244353;

ll p2[(int)2e5+10];

void solve() {
	int n; cin >> n;
	ll soma = 0, men = 0;
	vector<int> v(n);
	for (int& i : v) cin >> i, soma += i, men = min(men, soma);

	int x = 0;
	soma = 0;
	for (int i : v) soma += i, x += (soma == men);
	
	// se for pos, *2
	// no fim, ver em quantos pontos men aparece, chama essa q de x. 
	// depois faz res *= (1 << x) - 1;

	ll res = (x == 0 or x == 1 ? 1 : p2[x]-1);
	for (int i = 0; i < n; i++) {
		if (v[i] >= 0) {
			res <<= 1;
			res %= mod;
		} 
	}

	cout << res << endl;
}

int main()
{
    _;

	p2[0] = 1;
	for (int i = 1; i < (int)2e5+10; i++) {
		p2[i] = p2[i-1] * 2 % mod;
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
