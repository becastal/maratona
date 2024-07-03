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

const int MAX = 2 * 1e5 + 10;
int memo[MAX];

int dig(int x)
{
	int res = 0;
	while (x)
	{
		x /= 10;
		res++;
	}
	return res;
}

int somadig(int x)
{
	if (memo[x]) return memo[x];
	int tam = dig(x);
	int res = 0;
	while (tam--)
	{
		res += (x - (x % (int)pow(10, tam))) / (int)pow(10, tam);
		x -= (x - (x % (int)pow(10, tam)));
	}
	return memo[x] = res;
}

int main()
{
    _;

	memset(memo, 0, sizeof memo);
	for (int i = 1; i < MAX; i++)
		memo[i] = memo[i - 1] + somadig(i);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << memo[n] << endl;
	}
    
    return(0);
}
