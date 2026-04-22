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
// teoria dos numeros que parecia meio louca. ningem deciciu encarar nem nada.
// para que uma divisao seja uma dizima periodica, eh facil observar que basta o denominador ter um primo que nao divide a base. no caso da base 10, basta nao ser composto por 2 . 5 ou variacoes.
// com essa idea, basta encontrar todos os primos dos denominadores e multiplicar todos eles.

const int MAX = 1e5 + 10;
const int MOD = 998244353;
int tem[MAX];

vector<int> fact(int n) {
	vector<int> res;
	for (int i = 2; i <= n/i; i++)
		if (n%i == 0)
		{
			res.push_back(i);
			while (n%i == 0) n /= i;
		}
	if (n > 1) res.push_back(n);
	return res;
}
int main()
{
    _;

	int n; cin >> n;
	while (n--)
	{
		int a, b; cin >> a >> b;
		for (int i : fact(b / gcd(a, b)))
			tem[i] = 1;
	}

	if (accumulate(tem, tem + MAX, 0ll) == 0)
		return cout << 2 << endl, 0;

	ll res = 1;
	for (int i = 0; i < MAX; i++)
		if (tem[i])
			res = res * i % MOD;

	cout << res << endl;
    
    return(0);
}
