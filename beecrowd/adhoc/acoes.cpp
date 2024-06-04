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

	int d, i, x, f; cin >> d >> i >> x >> f;
	int soma = i;
	for (int j = d + 1; j <= d + f; j++)
	{
		if (j % 2 != 0)
			soma -= x;
		else
			soma += x;
	}
	cout << soma << endl;
    
    return(0);
}
