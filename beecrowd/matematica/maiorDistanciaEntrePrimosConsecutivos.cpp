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

vector<int> divi;

int crivo(int lim) {
	int ult = 0, maior = -INF;
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i)
		{
			divi[j] = i;
			if (j == i)
			{	
				maior = max(maior, i - ult);
				ult = i;
			}
		}
	return maior;
}

int main()
{
    _;

	int n;
	while (cin >> n)
	{
		divi.assign(n, 0);
		cout << crivo(n) << endl;
	}
    
    return(0);
}
