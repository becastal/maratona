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

	int n;
	while (cin >> n and n != -1)
	{
		int soma = 0, r = 0;
		for (int i = 0; i < n; i++)
		{
			int pi; cin >> pi;
			soma += pi;
			if (soma % 100 == 0)
				soma = 0, r++;
		}
		cout << r << endl;
	}
    
    return(0);
}
